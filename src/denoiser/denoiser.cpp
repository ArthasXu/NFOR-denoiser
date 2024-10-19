#include "Version.hpp"

#include "thread/ThreadUtils.hpp"

#include "io/JsonLoadException.hpp"
#include "io/CliParser.hpp"
#include "io/ImageIO.hpp"
#include "io/Scene.hpp"

#include "Regression.hpp"
#include "NlMeans.hpp"
#include "Pixmap.hpp"

#include "Logging.hpp"
#include "Memory.hpp"
#include "Timer.hpp"

#include <tinyformat/tinyformat.hpp>
#include <cstdlib>
#include <cstring>

using namespace Tungsten;

#define useVariance 0
#define useTwoBufferStrategy 0

static const int OPT_VERSION  = 0;
static const int OPT_HELP     = 1;

template<typename Texel>
struct RenderBuffer
{
    std::unique_ptr<Pixmap<Texel>> buffer;
    std::unique_ptr<Pixmap<Texel>> bufferA;
    std::unique_ptr<Pixmap<Texel>> bufferB;
    std::unique_ptr<Pixmap<Texel>> bufferVariance;
};
typedef RenderBuffer<float> RenderBufferF;
typedef RenderBuffer<Vec3f> RenderBuffer3f;

Pixmap3f nforDenoiser(RenderBuffer3f image, std::vector<RenderBufferF> features)
{
    if(useVariance){
        int w = image.buffer->w(), h = image.buffer->h();

        // Feature cross-prefiltering (section 5.1)
        printTimestampedLog("Prefiltering features...");
        std::vector<PixmapF> filteredFeaturesA(features.size());
        std::vector<PixmapF> filteredFeaturesB(features.size());
        SimdNlMeans featureFilter;
        for (size_t i = 0; i < features.size(); ++i) {
            featureFilter.addBuffer(filteredFeaturesA[i], *features[i].bufferA, *features[i].bufferB, *features[i].bufferVariance);
            featureFilter.addBuffer(filteredFeaturesB[i], *features[i].bufferB, *features[i].bufferA, *features[i].bufferVariance);
        }
        featureFilter.denoise(3, 5, 0.5f, 2.0f);
        features.clear();
        printTimestampedLog("Prefiltering done");

        // Main regression (section 5.2)
        std::vector<Pixmap3f> filteredColorsA;
        std::vector<Pixmap3f> filteredColorsB;
        std::vector<Pixmap3f> mses;
        for (float k : {0.5f, 1.0f}) {
            printTimestampedLog(tfm::format("Beginning regression pass %d/2", mses.size() + 1));
            // Regression pass
            printTimestampedLog("Denosing half buffer A...");
            Pixmap3f filteredColorA = collaborativeRegression(*image.bufferA, *image.bufferB, filteredFeaturesB, *image.bufferVariance, 3, 9, k);
            printTimestampedLog("Denosing half buffer B...");
            Pixmap3f filteredColorB = collaborativeRegression(*image.bufferB, *image.bufferA, filteredFeaturesA, *image.bufferVariance, 3, 9, k);

            // MSE estimation (section 5.3)
            printTimestampedLog("Estimating MSE...");
            Pixmap3f noisyMse(w, h);
            for (int i = 0; i < w*h; ++i) {
                Vec3f mseA = sqr((*image.bufferB)[i] - filteredColorA[i]) - 2.0f*(*image.bufferVariance)[i];
                Vec3f mseB = sqr((*image.bufferA)[i] - filteredColorB[i]) - 2.0f*(*image.bufferVariance)[i];
                Vec3f residualColorVariance = sqr(filteredColorB[i] - filteredColorA[i])*0.25f;

                noisyMse[i] = (mseA + mseB)*0.5f - residualColorVariance;
            }
            filteredColorsA.emplace_back(std::move(filteredColorA));
            filteredColorsB.emplace_back(std::move(filteredColorB));

            // MSE filtering
            mses.emplace_back(nlMeans(noisyMse, *image.buffer, *image.bufferVariance, 1, 9, 1.0f, 1.0f, true));
        }
        printTimestampedLog("Regression pass done");

        // Bandwidth selection (section 5.3)
        // Generate selection map
        printTimestampedLog("Generating selection maps...");
        Pixmap3f noisySelection(w, h);
        for (int i = 0; i < w*h; ++i)
            for (int j = 0; j < 3; ++j)
                noisySelection[i][j] = mses[0][i][j] < mses[1][i][j] ? 0.0f : 1.0f;
        mses.clear();
        // Filter selection map
        Pixmap3f selection = nlMeans(noisySelection, *image.buffer, *image.bufferVariance, 1, 9, 1.0f, 1.0f, true);

        // Apply selection map
        Pixmap3f resultA(w, h);
        Pixmap3f resultB(w, h);
        for (int i = 0; i < w*h; ++i) {
            resultA[i] += lerp(filteredColorsA[0][i], filteredColorsA[1][i], selection[i]);
            resultB[i] += lerp(filteredColorsB[0][i], filteredColorsB[1][i], selection[i]);
        }
        selection.reset();
        filteredColorsA.clear();
        filteredColorsB.clear();

        // Second filter pass (section 5.4)
        printTimestampedLog("Beginning second filter pass");
        printTimestampedLog("Denoising final features...");
        std::vector<PixmapF> finalFeatures;
        for (size_t i = 0; i < filteredFeaturesA.size(); ++i) {
            PixmapF combinedFeature(w, h);
            PixmapF combinedFeatureVar(w, h);

            for (int j = 0; j < w*h; ++j) {
                combinedFeature   [j] =    (filteredFeaturesA[i][j] + filteredFeaturesB[i][j])*0.5f;
                combinedFeatureVar[j] = sqr(filteredFeaturesB[i][j] - filteredFeaturesA[i][j])*0.25f;
            }
            filteredFeaturesA[i].reset();
            filteredFeaturesB[i].reset();

            finalFeatures.emplace_back(nlMeans(combinedFeature, combinedFeature, combinedFeatureVar, 3, 2, 0.5f));
        }

        Pixmap3f combinedResult(w, h);
        Pixmap3f combinedResultVar(w, h);
        for (int j = 0; j < w*h; ++j) {
            combinedResult   [j] =    (resultA[j] + resultB[j])*0.5f;
            combinedResultVar[j] = sqr(resultB[j] - resultA[j])*0.25f;
        }
        printTimestampedLog("Performing final regression...");
        return collaborativeRegression(combinedResult, combinedResult, finalFeatures, combinedResultVar, 3, 9, 1.0f);
    }
    else if(useTwoBufferStrategy){
        std::cout<<6<<std::endl;
        int w = image.buffer->w(), h = image.buffer->h();

        // Feature cross-prefiltering (section 5.1)
        printTimestampedLog("Prefiltering features...");
        std::vector<PixmapF> filteredFeaturesA(features.size());
        std::vector<PixmapF> filteredFeaturesB(features.size());
        SimdNlMeans featureFilter;
        for (size_t i = 0; i < features.size(); ++i) {
            featureFilter.addBuffer(filteredFeaturesA[i], *features[i].bufferA, *features[i].bufferB, *features[i].bufferVariance);
            featureFilter.addBuffer(filteredFeaturesB[i], *features[i].bufferB, *features[i].bufferA, *features[i].bufferVariance);
        }
        featureFilter.denoise(3, 5, 0.5f, 2.0f);
        features.clear();
        printTimestampedLog("Prefiltering done");

        // Main regression (section 5.2)
        std::vector<Pixmap3f> filteredColorsA;
        std::vector<Pixmap3f> filteredColorsB;

        printTimestampedLog(tfm::format("Beginning regression pass"));
        // Regression pass
        printTimestampedLog("Denosing half buffer A...");
        Pixmap3f filteredColorA = collaborativeRegression(*image.bufferA, *image.bufferB, filteredFeaturesB, *image.bufferVariance, 3, 9, 0.5f);
        printTimestampedLog("Denosing half buffer B...");
        Pixmap3f filteredColorB = collaborativeRegression(*image.bufferB, *image.bufferA, filteredFeaturesA, *image.bufferVariance, 3, 9, 0.5f);

        filteredColorsA.emplace_back(std::move(filteredColorA));
        filteredColorsB.emplace_back(std::move(filteredColorB));
        printTimestampedLog("Regression pass done");

        // Apply selection map
        Pixmap3f resultA(w, h);
        Pixmap3f resultB(w, h);
        for (int i = 0; i < w*h; ++i) {
            resultA[i] += filteredColorsA[0][i];
            resultB[i] += filteredColorsB[0][i];
        }
        filteredColorsA.clear();
        filteredColorsB.clear();

        // Second filter pass (section 5.4)
        printTimestampedLog("Beginning second filter pass");
        printTimestampedLog("Denoising final features...");
        std::vector<PixmapF> finalFeatures;
        for (size_t i = 0; i < filteredFeaturesA.size(); ++i) {
            PixmapF combinedFeature(w, h);
            PixmapF combinedFeatureVar(w, h);

            for (int j = 0; j < w*h; ++j) {
                combinedFeature   [j] =    (filteredFeaturesA[i][j] + filteredFeaturesB[i][j])*0.5f;
                combinedFeatureVar[j] = sqr(filteredFeaturesB[i][j] - filteredFeaturesA[i][j])*0.25f;
            }
            filteredFeaturesA[i].reset();
            filteredFeaturesB[i].reset();

            finalFeatures.emplace_back(nlMeans(combinedFeature, combinedFeature, combinedFeatureVar, 3, 2, 0.5f));
        }

        Pixmap3f combinedResult(w, h);
        Pixmap3f combinedResultVar(w, h);
        for (int j = 0; j < w*h; ++j) {
            combinedResult   [j] =    (resultA[j] + resultB[j])*0.5f;
            combinedResultVar[j] = sqr(resultB[j] - resultA[j])*0.25f;
        }
        printTimestampedLog("Performing final regression...");
        return collaborativeRegression(combinedResult, combinedResult, finalFeatures, combinedResultVar, 3, 9, 1.0f);
    }
    else{
        std::cout<<6<<std::endl;
        int w = image.buffer->w(), h = image.buffer->h();

        // Feature cross-prefiltering (section 5.1)
        printTimestampedLog("Prefiltering features...");
        std::vector<PixmapF> filteredFeatures(features.size());
        SimdNlMeans featureFilter;
        for (size_t i = 0; i < features.size(); ++i) {
            featureFilter.addBuffer(filteredFeatures[i], *features[i].bufferA, *features[i].bufferB, *features[i].bufferVariance);
        }
        featureFilter.denoise(3, 5, 0.5f, 2.0f);
        features.clear();
        printTimestampedLog("Prefiltering done");

        // Main regression (section 5.2)
        std::vector<Pixmap3f> filteredColors;

        printTimestampedLog(tfm::format("Beginning regression pass"));
        // Regression pass
        printTimestampedLog("Denosing buffer...");
        Pixmap3f filteredColor = collaborativeRegression(*image.bufferA, *image.bufferB, filteredFeatures, *image.bufferVariance, 3, 9, 0.5f);

        filteredColors.emplace_back(std::move(filteredColor));
        printTimestampedLog("Regression pass done");

        // Apply selection map
        Pixmap3f result(w, h);
        for (int i = 0; i < w*h; ++i) {
            result[i] += filteredColors[0][i];
        }
        filteredColors.clear();

        // Second filter pass (section 5.4)
        printTimestampedLog("Beginning second filter pass");
        printTimestampedLog("Denoising final features...");
        std::vector<PixmapF> finalFeatures;
        for (size_t i = 0; i < filteredFeatures.size(); ++i) {
            PixmapF combinedFeature(w, h);
            PixmapF combinedFeatureVar(w, h);

            for (int j = 0; j < w*h; ++j) {
                combinedFeature[j] = filteredFeatures[i][j];
            }
            filteredFeatures[i].reset();

            finalFeatures.emplace_back(nlMeans(combinedFeature, combinedFeature, combinedFeatureVar, 3, 2, 0.5f));
        }

        Pixmap3f combinedResult(w, h);
        Pixmap3f combinedResultVar(w, h);
        for (int j = 0; j < w*h; ++j) {
            combinedResult[j] = result[j];
        }
        printTimestampedLog("Performing final regression...");
        return collaborativeRegression(combinedResult, combinedResult, finalFeatures, combinedResultVar, 3, 9, 1.0f);
    }
}

// Extracts a single channel of an RGB image into a separate pixmap
std::unique_ptr<PixmapF> slicePixmap(const Pixmap3f &src, int channel)
{
    int w = src.w(), h = src.h();

    auto result = std::unique_ptr<PixmapF>(new PixmapF(w, h));
    for (int j = 0; j < w*h; ++j)
        (*result)[j] = src[j][channel];

    return std::move(result);
}

void loadInputBuffers(RenderBuffer3f &image, std::vector<RenderBufferF> &features, const Scene &scene)
{
    for (const auto &b : scene.rendererSettings().renderOutputs()) {
        if (!b.hdrOutputFile().empty()) {
            Path file = b.hdrOutputFile();
            std::cout<<"file.workingDirectory: "<<file._workingDirectory<<"\n"<<"file._path: "<<file._path<<"\n";
            std::cout<<"file.stripExtension: "<<file.stripExtension()<<"\n"<<"file.extension(): "<<file.extension()<<"\n";
            std::cout<<std::endl;
            auto buffer = loadPixmap<Vec3f>(file, true);
            if (buffer) {
                std::unique_ptr<Pixmap3f> bufferVariance;
                if (b.sampleVariance()) {
                    Path varianceFile = file.stripExtension() + "Variance" + file.extension();
                    bufferVariance = loadPixmap<Vec3f>(varianceFile);
                }
                std::unique_ptr<Pixmap3f> bufferA, bufferB;
                if (b.twoBufferVariance()) {
                    Path fileA = file.stripExtension() + "A" + file.extension();
                    Path fileB = file.stripExtension() + "B" + file.extension();
                    bufferA = loadPixmap<Vec3f>(fileA);
                    bufferB = loadPixmap<Vec3f>(fileB);
                }
                if (b.type() == OutputColor) {
                    image.buffer         = std::move(buffer);
                    image.bufferA        = std::move(bufferA);
                    image.bufferB        = std::move(bufferB);
                    image.bufferVariance = std::move(bufferVariance);
                } else {
                    bool isRgb = (b.type() == OutputNormal || b.type() == OutputAlbedo);
                    for (int i = 0; i < (isRgb ? 3 : 1); ++i) {
                        features.emplace_back();
                        if (buffer        ) features.back().buffer         = slicePixmap(*buffer        , i);
                        if (bufferA       ) features.back().bufferA        = slicePixmap(*bufferA       , i);
                        if (bufferB       ) features.back().bufferB        = slicePixmap(*bufferB       , i);
                        if (bufferVariance) features.back().bufferVariance = slicePixmap(*bufferVariance, i);
                    }
                    printTimestampedLog(tfm::format("Using feature %s", b.typeString()));
                }
            }
        }
    }
}

void loadInputBuffersFromDirectory(RenderBuffer3f &image, std::vector<RenderBufferF> &features, const std::string &workingDirectory) {
    std::vector<std::string> colorFiles, albedoFiles, normalFiles;
    if(useTwoBufferStrategy){
        colorFiles = {"color.exr", "colorA.exr", "colorB.exr", "colorVariance.exr"};
        albedoFiles = {"albedo.exr", "albedoA.exr", "albedoB.exr", "albedoVariance.exr"};
        normalFiles = {"normal.exr", "normalA.exr", "normalB.exr", "normalVariance.exr"};
    }
    else{
        colorFiles = {"ensemble_1280.exr", "ensemble_1280.exr", "ensemble_1280.exr", "colorVariance.exr"};
        albedoFiles = {"albedo_1280.exr", "albedo_1280.exr", "albedo_1280.exr", "albedoVariance.exr"};
        normalFiles = {"normal_1280.exr", "normal_1280.exr", "normal_1280.exr", "normalVariance.exr"};
    }

    std::cout<<2<<std::endl;

    //Color
    auto buffer = loadPixmap<Vec3f>(Path(workingDirectory, colorFiles[0]), true);
    if (buffer) {
        auto bufferVariance = loadPixmap<Vec3f>(Path(workingDirectory, colorFiles[3]));
        auto bufferA = loadPixmap<Vec3f>(Path(workingDirectory, colorFiles[1]));
        auto bufferB = loadPixmap<Vec3f>(Path(workingDirectory, colorFiles[2]));

        image.buffer = std::move(buffer);
        image.bufferA = std::move(bufferA);
        image.bufferB = std::move(bufferB);
        image.bufferVariance = std::move(bufferVariance);
    }

    std::cout<<3<<std::endl;

    //Albedo
    auto albedoBuffer = loadPixmap<Vec3f>(Path(workingDirectory, albedoFiles[0]), true);
    if (albedoBuffer) {
        auto albedoVariance = loadPixmap<Vec3f>(Path(workingDirectory, albedoFiles[3])); 
        auto albedoBufferA = loadPixmap<Vec3f>(Path(workingDirectory, albedoFiles[1]));
        auto albedoBufferB = loadPixmap<Vec3f>(Path(workingDirectory, albedoFiles[2]));

        for (int i = 0; i < 3; ++i) {
            features.emplace_back();
            features.back().buffer = slicePixmap(*albedoBuffer, i);
            if (albedoBufferA) features.back().bufferA = slicePixmap(*albedoBufferA, i);
            if (albedoBufferB) features.back().bufferB = slicePixmap(*albedoBufferB, i);
            if (albedoVariance) features.back().bufferVariance = slicePixmap(*albedoVariance, i);
        }
    }

    std::cout<<4<<std::endl;

    //Normal
    auto normalBuffer = loadPixmap<Vec3f>(Path(workingDirectory, normalFiles[0]), true);
    if (normalBuffer) {
        auto normalVariance = loadPixmap<Vec3f>(Path(workingDirectory, normalFiles[3]));
        auto normalBufferA = loadPixmap<Vec3f>(Path(workingDirectory, normalFiles[1]));
        auto normalBufferB = loadPixmap<Vec3f>(Path(workingDirectory, normalFiles[2]));

        for (int i = 0; i < 3; ++i) {
            features.emplace_back();
            features.back().buffer = slicePixmap(*normalBuffer, i);
            if (normalBufferA) features.back().bufferA = slicePixmap(*normalBufferA, i);
            if (normalBufferB) features.back().bufferB = slicePixmap(*normalBufferB, i);
            if (normalVariance) features.back().bufferVariance = slicePixmap(*normalVariance, i);
        }
    }

    std::cout<<5<<std::endl;
}

template<typename Texel>
void printPixmap(const std::unique_ptr<Pixmap<Texel>> &buffer, const std::string &name) {
    if (!buffer) {
        std::cout << name << ": Empty\n";
        return;
    }
    std::cout << name << ": " << buffer->w() << "x" << buffer->h() << "\n";
    for (int y = 0; y < buffer->h(); ++y) {
        for (int x = 0; x < buffer->w(); ++x) {
            std::cout << (*buffer)(x, y) << " ";
        }
        std::cout << "\n";
    }
}

template<typename Texel>
void printRenderBuffer(const RenderBuffer<Texel> &rb) {
    printPixmap(rb.buffer, "buffer");
    printPixmap(rb.bufferA, "bufferA");
    printPixmap(rb.bufferB, "bufferB");
    printPixmap(rb.bufferVariance, "bufferVariance");
}

void printImageAndFeatures(const RenderBuffer3f &image, const std::vector<RenderBufferF> &features) {
    std::cout << "Image:\n";
    printRenderBuffer(image);

    std::cout << "Features:\n";
    for (size_t i = 0; i < features.size(); ++i) {
        std::cout << "Feature " << i << ":\n";
        printRenderBuffer(features[i]);
    }
}

// denoiser path/ output.exr
int main(int argc, const char *argv[])
{
    CliParser parser("denoiser", "[options] scene outputfile");
    parser.addOption('h', "help", "Prints this help text", false, OPT_HELP);
    parser.addOption('v', "version", "Prints version information", false, OPT_VERSION);

    parser.parse(argc, argv);
    if (parser.isPresent(OPT_VERSION)) {
        std::cout << "denoiser, version " << VERSION_STRING << std::endl;
        return 0;
    }
    if (parser.operands().size() != 2 || parser.isPresent(OPT_HELP)) {
        parser.printHelpText();
        return 0;
    }

    // Path sceneFile(parser.operands()[0]);
    Path targetFile(parser.operands()[1]);

    // printTimestampedLog(tfm::format("Loading scene '%s'...", sceneFile));

    // std::unique_ptr<Scene> scene;
    // try {
    //     scene.reset(Scene::load(sceneFile));
    // } catch (const JsonLoadException &e) {
    //     std::cerr << e.what() << std::endl;
    //     return 1;
    // }

    ThreadUtils::startThreads(max(ThreadUtils::idealThreadCount() - 1, 1u));

    std::cout<<1<<std::endl;

    RenderBuffer3f image;
    std::vector<RenderBufferF> features;
    // loadInputBuffers(image, features, *scene);
    loadInputBuffersFromDirectory(image, features, parser.operands()[0]);
    // printImageAndFeatures(image, features);

    Timer timer;
    Pixmap3f result = nforDenoiser(std::move(image), std::move(features));
    timer.stop();
    printTimestampedLog(tfm::format("Filtering complete! Filter time: %.1fs", timer.elapsed()));

    result.save(targetFile, true);

    return 0;
}

