# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/lib64/python3.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib64/python3.7/site-packages/cmake/data/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ec2-user/tirta/supercomp2/projeto-03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ec2-user/tirta/supercomp2/projeto-03/build

# Include any dependencies generated for this target.
include CMakeFiles/tsp-par.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tsp-par.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tsp-par.dir/flags.make

CMakeFiles/tsp-par.dir/tsp-par.cpp.o: CMakeFiles/tsp-par.dir/flags.make
CMakeFiles/tsp-par.dir/tsp-par.cpp.o: ../tsp-par.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ec2-user/tirta/supercomp2/projeto-03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tsp-par.dir/tsp-par.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tsp-par.dir/tsp-par.cpp.o -c /home/ec2-user/tirta/supercomp2/projeto-03/tsp-par.cpp

CMakeFiles/tsp-par.dir/tsp-par.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tsp-par.dir/tsp-par.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ec2-user/tirta/supercomp2/projeto-03/tsp-par.cpp > CMakeFiles/tsp-par.dir/tsp-par.cpp.i

CMakeFiles/tsp-par.dir/tsp-par.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tsp-par.dir/tsp-par.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ec2-user/tirta/supercomp2/projeto-03/tsp-par.cpp -o CMakeFiles/tsp-par.dir/tsp-par.cpp.s

# Object files for target tsp-par
tsp__par_OBJECTS = \
"CMakeFiles/tsp-par.dir/tsp-par.cpp.o"

# External object files for target tsp-par
tsp__par_EXTERNAL_OBJECTS =

tsp-par: CMakeFiles/tsp-par.dir/tsp-par.cpp.o
tsp-par: CMakeFiles/tsp-par.dir/build.make
tsp-par: /usr/lib/gcc/x86_64-redhat-linux/7/libgomp.so
tsp-par: /usr/lib64/libpthread.so
tsp-par: CMakeFiles/tsp-par.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ec2-user/tirta/supercomp2/projeto-03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tsp-par"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tsp-par.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tsp-par.dir/build: tsp-par

.PHONY : CMakeFiles/tsp-par.dir/build

CMakeFiles/tsp-par.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tsp-par.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tsp-par.dir/clean

CMakeFiles/tsp-par.dir/depend:
	cd /home/ec2-user/tirta/supercomp2/projeto-03/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ec2-user/tirta/supercomp2/projeto-03 /home/ec2-user/tirta/supercomp2/projeto-03 /home/ec2-user/tirta/supercomp2/projeto-03/build /home/ec2-user/tirta/supercomp2/projeto-03/build /home/ec2-user/tirta/supercomp2/projeto-03/build/CMakeFiles/tsp-par.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tsp-par.dir/depend

