# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/rokner/Installs/clion-2017.1.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/rokner/Installs/clion-2017.1.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rokner/Programming/FGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rokner/Programming/FGL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FGL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FGL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FGL.dir/flags.make

CMakeFiles/FGL.dir/src/Application.cpp.o: CMakeFiles/FGL.dir/flags.make
CMakeFiles/FGL.dir/src/Application.cpp.o: ../src/Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rokner/Programming/FGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FGL.dir/src/Application.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FGL.dir/src/Application.cpp.o -c /home/rokner/Programming/FGL/src/Application.cpp

CMakeFiles/FGL.dir/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FGL.dir/src/Application.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rokner/Programming/FGL/src/Application.cpp > CMakeFiles/FGL.dir/src/Application.cpp.i

CMakeFiles/FGL.dir/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FGL.dir/src/Application.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rokner/Programming/FGL/src/Application.cpp -o CMakeFiles/FGL.dir/src/Application.cpp.s

CMakeFiles/FGL.dir/src/Application.cpp.o.requires:

.PHONY : CMakeFiles/FGL.dir/src/Application.cpp.o.requires

CMakeFiles/FGL.dir/src/Application.cpp.o.provides: CMakeFiles/FGL.dir/src/Application.cpp.o.requires
	$(MAKE) -f CMakeFiles/FGL.dir/build.make CMakeFiles/FGL.dir/src/Application.cpp.o.provides.build
.PHONY : CMakeFiles/FGL.dir/src/Application.cpp.o.provides

CMakeFiles/FGL.dir/src/Application.cpp.o.provides.build: CMakeFiles/FGL.dir/src/Application.cpp.o


CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o: CMakeFiles/FGL.dir/flags.make
CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o: ../src/FloatingNetwork.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rokner/Programming/FGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o -c /home/rokner/Programming/FGL/src/FloatingNetwork.cpp

CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rokner/Programming/FGL/src/FloatingNetwork.cpp > CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.i

CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rokner/Programming/FGL/src/FloatingNetwork.cpp -o CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.s

CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o.requires:

.PHONY : CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o.requires

CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o.provides: CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o.requires
	$(MAKE) -f CMakeFiles/FGL.dir/build.make CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o.provides.build
.PHONY : CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o.provides

CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o.provides.build: CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o


CMakeFiles/FGL.dir/src/GameHandler.cpp.o: CMakeFiles/FGL.dir/flags.make
CMakeFiles/FGL.dir/src/GameHandler.cpp.o: ../src/GameHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rokner/Programming/FGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FGL.dir/src/GameHandler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FGL.dir/src/GameHandler.cpp.o -c /home/rokner/Programming/FGL/src/GameHandler.cpp

CMakeFiles/FGL.dir/src/GameHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FGL.dir/src/GameHandler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rokner/Programming/FGL/src/GameHandler.cpp > CMakeFiles/FGL.dir/src/GameHandler.cpp.i

CMakeFiles/FGL.dir/src/GameHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FGL.dir/src/GameHandler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rokner/Programming/FGL/src/GameHandler.cpp -o CMakeFiles/FGL.dir/src/GameHandler.cpp.s

CMakeFiles/FGL.dir/src/GameHandler.cpp.o.requires:

.PHONY : CMakeFiles/FGL.dir/src/GameHandler.cpp.o.requires

CMakeFiles/FGL.dir/src/GameHandler.cpp.o.provides: CMakeFiles/FGL.dir/src/GameHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/FGL.dir/build.make CMakeFiles/FGL.dir/src/GameHandler.cpp.o.provides.build
.PHONY : CMakeFiles/FGL.dir/src/GameHandler.cpp.o.provides

CMakeFiles/FGL.dir/src/GameHandler.cpp.o.provides.build: CMakeFiles/FGL.dir/src/GameHandler.cpp.o


CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o: CMakeFiles/FGL.dir/flags.make
CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o: ../src/UpdateInfo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rokner/Programming/FGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o -c /home/rokner/Programming/FGL/src/UpdateInfo.cpp

CMakeFiles/FGL.dir/src/UpdateInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FGL.dir/src/UpdateInfo.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rokner/Programming/FGL/src/UpdateInfo.cpp > CMakeFiles/FGL.dir/src/UpdateInfo.cpp.i

CMakeFiles/FGL.dir/src/UpdateInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FGL.dir/src/UpdateInfo.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rokner/Programming/FGL/src/UpdateInfo.cpp -o CMakeFiles/FGL.dir/src/UpdateInfo.cpp.s

CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o.requires:

.PHONY : CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o.requires

CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o.provides: CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o.requires
	$(MAKE) -f CMakeFiles/FGL.dir/build.make CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o.provides.build
.PHONY : CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o.provides

CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o.provides.build: CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o


CMakeFiles/FGL.dir/src/main.cpp.o: CMakeFiles/FGL.dir/flags.make
CMakeFiles/FGL.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rokner/Programming/FGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FGL.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FGL.dir/src/main.cpp.o -c /home/rokner/Programming/FGL/src/main.cpp

CMakeFiles/FGL.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FGL.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rokner/Programming/FGL/src/main.cpp > CMakeFiles/FGL.dir/src/main.cpp.i

CMakeFiles/FGL.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FGL.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rokner/Programming/FGL/src/main.cpp -o CMakeFiles/FGL.dir/src/main.cpp.s

CMakeFiles/FGL.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/FGL.dir/src/main.cpp.o.requires

CMakeFiles/FGL.dir/src/main.cpp.o.provides: CMakeFiles/FGL.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/FGL.dir/build.make CMakeFiles/FGL.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/FGL.dir/src/main.cpp.o.provides

CMakeFiles/FGL.dir/src/main.cpp.o.provides.build: CMakeFiles/FGL.dir/src/main.cpp.o


# Object files for target FGL
FGL_OBJECTS = \
"CMakeFiles/FGL.dir/src/Application.cpp.o" \
"CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o" \
"CMakeFiles/FGL.dir/src/GameHandler.cpp.o" \
"CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o" \
"CMakeFiles/FGL.dir/src/main.cpp.o"

# External object files for target FGL
FGL_EXTERNAL_OBJECTS =

FGL: CMakeFiles/FGL.dir/src/Application.cpp.o
FGL: CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o
FGL: CMakeFiles/FGL.dir/src/GameHandler.cpp.o
FGL: CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o
FGL: CMakeFiles/FGL.dir/src/main.cpp.o
FGL: CMakeFiles/FGL.dir/build.make
FGL: CMakeFiles/FGL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rokner/Programming/FGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable FGL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FGL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FGL.dir/build: FGL

.PHONY : CMakeFiles/FGL.dir/build

CMakeFiles/FGL.dir/requires: CMakeFiles/FGL.dir/src/Application.cpp.o.requires
CMakeFiles/FGL.dir/requires: CMakeFiles/FGL.dir/src/FloatingNetwork.cpp.o.requires
CMakeFiles/FGL.dir/requires: CMakeFiles/FGL.dir/src/GameHandler.cpp.o.requires
CMakeFiles/FGL.dir/requires: CMakeFiles/FGL.dir/src/UpdateInfo.cpp.o.requires
CMakeFiles/FGL.dir/requires: CMakeFiles/FGL.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/FGL.dir/requires

CMakeFiles/FGL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FGL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FGL.dir/clean

CMakeFiles/FGL.dir/depend:
	cd /home/rokner/Programming/FGL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rokner/Programming/FGL /home/rokner/Programming/FGL /home/rokner/Programming/FGL/cmake-build-debug /home/rokner/Programming/FGL/cmake-build-debug /home/rokner/Programming/FGL/cmake-build-debug/CMakeFiles/FGL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FGL.dir/depend

