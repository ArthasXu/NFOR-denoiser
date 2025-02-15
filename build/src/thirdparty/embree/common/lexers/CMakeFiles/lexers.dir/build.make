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
include src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/depend.make

# Include the progress variables for this target.
include src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/progress.make

# Include the compile flags for this target's objects.
include src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/flags.make

src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/stringstream.cpp.o: src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/flags.make
src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/stringstream.cpp.o: ../src/thirdparty/embree/common/lexers/stringstream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xkh/Desktop/tungsten/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/stringstream.cpp.o"
	cd /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lexers.dir/stringstream.cpp.o -c /home/xkh/Desktop/tungsten/src/thirdparty/embree/common/lexers/stringstream.cpp

src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/stringstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lexers.dir/stringstream.cpp.i"
	cd /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xkh/Desktop/tungsten/src/thirdparty/embree/common/lexers/stringstream.cpp > CMakeFiles/lexers.dir/stringstream.cpp.i

src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/stringstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lexers.dir/stringstream.cpp.s"
	cd /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xkh/Desktop/tungsten/src/thirdparty/embree/common/lexers/stringstream.cpp -o CMakeFiles/lexers.dir/stringstream.cpp.s

src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/tokenstream.cpp.o: src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/flags.make
src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/tokenstream.cpp.o: ../src/thirdparty/embree/common/lexers/tokenstream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xkh/Desktop/tungsten/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/tokenstream.cpp.o"
	cd /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lexers.dir/tokenstream.cpp.o -c /home/xkh/Desktop/tungsten/src/thirdparty/embree/common/lexers/tokenstream.cpp

src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/tokenstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lexers.dir/tokenstream.cpp.i"
	cd /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xkh/Desktop/tungsten/src/thirdparty/embree/common/lexers/tokenstream.cpp > CMakeFiles/lexers.dir/tokenstream.cpp.i

src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/tokenstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lexers.dir/tokenstream.cpp.s"
	cd /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xkh/Desktop/tungsten/src/thirdparty/embree/common/lexers/tokenstream.cpp -o CMakeFiles/lexers.dir/tokenstream.cpp.s

# Object files for target lexers
lexers_OBJECTS = \
"CMakeFiles/lexers.dir/stringstream.cpp.o" \
"CMakeFiles/lexers.dir/tokenstream.cpp.o"

# External object files for target lexers
lexers_EXTERNAL_OBJECTS =

src/thirdparty/embree/liblexers.a: src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/stringstream.cpp.o
src/thirdparty/embree/liblexers.a: src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/tokenstream.cpp.o
src/thirdparty/embree/liblexers.a: src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/build.make
src/thirdparty/embree/liblexers.a: src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xkh/Desktop/tungsten/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../liblexers.a"
	cd /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers && $(CMAKE_COMMAND) -P CMakeFiles/lexers.dir/cmake_clean_target.cmake
	cd /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lexers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/build: src/thirdparty/embree/liblexers.a

.PHONY : src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/build

src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/clean:
	cd /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers && $(CMAKE_COMMAND) -P CMakeFiles/lexers.dir/cmake_clean.cmake
.PHONY : src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/clean

src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/depend:
	cd /home/xkh/Desktop/tungsten/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xkh/Desktop/tungsten /home/xkh/Desktop/tungsten/src/thirdparty/embree/common/lexers /home/xkh/Desktop/tungsten/build /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers /home/xkh/Desktop/tungsten/build/src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/thirdparty/embree/common/lexers/CMakeFiles/lexers.dir/depend

