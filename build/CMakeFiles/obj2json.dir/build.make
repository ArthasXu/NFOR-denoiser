# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xkh/Desktop/tungsten

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xkh/Desktop/tungsten/build

# Include any dependencies generated for this target.
include CMakeFiles/obj2json.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/obj2json.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/obj2json.dir/flags.make

CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.o: CMakeFiles/obj2json.dir/flags.make
CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.o: ../src/obj2json/obj2json.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xkh/Desktop/tungsten/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.o -c /home/xkh/Desktop/tungsten/src/obj2json/obj2json.cpp

CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xkh/Desktop/tungsten/src/obj2json/obj2json.cpp > CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.i

CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xkh/Desktop/tungsten/src/obj2json/obj2json.cpp -o CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.s

# Object files for target obj2json
obj2json_OBJECTS = \
"CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.o"

# External object files for target obj2json
obj2json_EXTERNAL_OBJECTS =

obj2json: CMakeFiles/obj2json.dir/src/obj2json/obj2json.cpp.o
obj2json: CMakeFiles/obj2json.dir/build.make
obj2json: libcore.a
obj2json: libthirdparty.a
obj2json: src/thirdparty/embree/libembree.a
obj2json: /usr/lib/x86_64-linux-gnu/libIlmImf.so
obj2json: /usr/lib/x86_64-linux-gnu/libIlmThread.so
obj2json: /usr/lib/x86_64-linux-gnu/libImath.so
obj2json: /usr/lib/x86_64-linux-gnu/libHalf.so
obj2json: /usr/lib/x86_64-linux-gnu/libIex.so
obj2json: /usr/lib/x86_64-linux-gnu/libz.so
obj2json: /usr/lib/x86_64-linux-gnu/libjpeg.so
obj2json: src/thirdparty/embree/libembree_sse42.a
obj2json: src/thirdparty/embree/libsimd.a
obj2json: src/thirdparty/embree/liblexers.a
obj2json: src/thirdparty/embree/libsys.a
obj2json: CMakeFiles/obj2json.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xkh/Desktop/tungsten/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable obj2json"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/obj2json.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/obj2json.dir/build: obj2json

.PHONY : CMakeFiles/obj2json.dir/build

CMakeFiles/obj2json.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/obj2json.dir/cmake_clean.cmake
.PHONY : CMakeFiles/obj2json.dir/clean

CMakeFiles/obj2json.dir/depend:
	cd /home/xkh/Desktop/tungsten/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xkh/Desktop/tungsten /home/xkh/Desktop/tungsten /home/xkh/Desktop/tungsten/build /home/xkh/Desktop/tungsten/build /home/xkh/Desktop/tungsten/build/CMakeFiles/obj2json.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/obj2json.dir/depend

