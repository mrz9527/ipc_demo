# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/zhoukang/projects/mygithub/ipc_demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhoukang/projects/mygithub/ipc_demo/build

# Include any dependencies generated for this target.
include timer/CMakeFiles/timer_setitimer.dir/depend.make

# Include the progress variables for this target.
include timer/CMakeFiles/timer_setitimer.dir/progress.make

# Include the compile flags for this target's objects.
include timer/CMakeFiles/timer_setitimer.dir/flags.make

timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o: timer/CMakeFiles/timer_setitimer.dir/flags.make
timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o: ../timer/定时器_setitimer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoukang/projects/mygithub/ipc_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/timer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o -c /home/zhoukang/projects/mygithub/ipc_demo/timer/定时器_setitimer.cpp

timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.i"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/timer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoukang/projects/mygithub/ipc_demo/timer/定时器_setitimer.cpp > CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.i

timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.s"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/timer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoukang/projects/mygithub/ipc_demo/timer/定时器_setitimer.cpp -o CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.s

timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o.requires:

.PHONY : timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o.requires

timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o.provides: timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o.requires
	$(MAKE) -f timer/CMakeFiles/timer_setitimer.dir/build.make timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o.provides.build
.PHONY : timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o.provides

timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o.provides.build: timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o


# Object files for target timer_setitimer
timer_setitimer_OBJECTS = \
"CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o"

# External object files for target timer_setitimer
timer_setitimer_EXTERNAL_OBJECTS =

timer/timer_setitimer: timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o
timer/timer_setitimer: timer/CMakeFiles/timer_setitimer.dir/build.make
timer/timer_setitimer: timer/CMakeFiles/timer_setitimer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhoukang/projects/mygithub/ipc_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable timer_setitimer"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/timer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timer_setitimer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
timer/CMakeFiles/timer_setitimer.dir/build: timer/timer_setitimer

.PHONY : timer/CMakeFiles/timer_setitimer.dir/build

timer/CMakeFiles/timer_setitimer.dir/requires: timer/CMakeFiles/timer_setitimer.dir/定时器_setitimer.cpp.o.requires

.PHONY : timer/CMakeFiles/timer_setitimer.dir/requires

timer/CMakeFiles/timer_setitimer.dir/clean:
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/timer && $(CMAKE_COMMAND) -P CMakeFiles/timer_setitimer.dir/cmake_clean.cmake
.PHONY : timer/CMakeFiles/timer_setitimer.dir/clean

timer/CMakeFiles/timer_setitimer.dir/depend:
	cd /home/zhoukang/projects/mygithub/ipc_demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhoukang/projects/mygithub/ipc_demo /home/zhoukang/projects/mygithub/ipc_demo/timer /home/zhoukang/projects/mygithub/ipc_demo/build /home/zhoukang/projects/mygithub/ipc_demo/build/timer /home/zhoukang/projects/mygithub/ipc_demo/build/timer/CMakeFiles/timer_setitimer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : timer/CMakeFiles/timer_setitimer.dir/depend
