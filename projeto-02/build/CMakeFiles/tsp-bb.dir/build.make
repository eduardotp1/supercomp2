# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/tirta/supercomp/projeto-02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tirta/supercomp/projeto-02/build

# Include any dependencies generated for this target.
include CMakeFiles/tsp-bb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tsp-bb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tsp-bb.dir/flags.make

CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o: CMakeFiles/tsp-bb.dir/flags.make
CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o: ../tsp-bb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tirta/supercomp/projeto-02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o -c /home/tirta/supercomp/projeto-02/tsp-bb.cpp

CMakeFiles/tsp-bb.dir/tsp-bb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tsp-bb.dir/tsp-bb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tirta/supercomp/projeto-02/tsp-bb.cpp > CMakeFiles/tsp-bb.dir/tsp-bb.cpp.i

CMakeFiles/tsp-bb.dir/tsp-bb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tsp-bb.dir/tsp-bb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tirta/supercomp/projeto-02/tsp-bb.cpp -o CMakeFiles/tsp-bb.dir/tsp-bb.cpp.s

CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o.requires:

.PHONY : CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o.requires

CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o.provides: CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o.requires
	$(MAKE) -f CMakeFiles/tsp-bb.dir/build.make CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o.provides.build
.PHONY : CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o.provides

CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o.provides.build: CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o


# Object files for target tsp-bb
tsp__bb_OBJECTS = \
"CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o"

# External object files for target tsp-bb
tsp__bb_EXTERNAL_OBJECTS =

tsp-bb: CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o
tsp-bb: CMakeFiles/tsp-bb.dir/build.make
tsp-bb: /usr/lib/gcc/x86_64-linux-gnu/7/libgomp.so
tsp-bb: /usr/lib/x86_64-linux-gnu/libpthread.so
tsp-bb: CMakeFiles/tsp-bb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tirta/supercomp/projeto-02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tsp-bb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tsp-bb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tsp-bb.dir/build: tsp-bb

.PHONY : CMakeFiles/tsp-bb.dir/build

CMakeFiles/tsp-bb.dir/requires: CMakeFiles/tsp-bb.dir/tsp-bb.cpp.o.requires

.PHONY : CMakeFiles/tsp-bb.dir/requires

CMakeFiles/tsp-bb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tsp-bb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tsp-bb.dir/clean

CMakeFiles/tsp-bb.dir/depend:
	cd /home/tirta/supercomp/projeto-02/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tirta/supercomp/projeto-02 /home/tirta/supercomp/projeto-02 /home/tirta/supercomp/projeto-02/build /home/tirta/supercomp/projeto-02/build /home/tirta/supercomp/projeto-02/build/CMakeFiles/tsp-bb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tsp-bb.dir/depend

