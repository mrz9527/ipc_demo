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
include new/CMakeFiles/operator_new.dir/depend.make

# Include the progress variables for this target.
include new/CMakeFiles/operator_new.dir/progress.make

# Include the compile flags for this target's objects.
include new/CMakeFiles/operator_new.dir/flags.make

new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o: new/CMakeFiles/operator_new.dir/flags.make
new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o: ../new/重载new_delete.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoukang/projects/mygithub/ipc_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/new && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/operator_new.dir/重载new_delete.cpp.o -c /home/zhoukang/projects/mygithub/ipc_demo/new/重载new_delete.cpp

new/CMakeFiles/operator_new.dir/重载new_delete.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operator_new.dir/重载new_delete.cpp.i"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/new && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoukang/projects/mygithub/ipc_demo/new/重载new_delete.cpp > CMakeFiles/operator_new.dir/重载new_delete.cpp.i

new/CMakeFiles/operator_new.dir/重载new_delete.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operator_new.dir/重载new_delete.cpp.s"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/new && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoukang/projects/mygithub/ipc_demo/new/重载new_delete.cpp -o CMakeFiles/operator_new.dir/重载new_delete.cpp.s

new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o.requires:

.PHONY : new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o.requires

new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o.provides: new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o.requires
	$(MAKE) -f new/CMakeFiles/operator_new.dir/build.make new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o.provides.build
.PHONY : new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o.provides

new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o.provides.build: new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o


# Object files for target operator_new
operator_new_OBJECTS = \
"CMakeFiles/operator_new.dir/重载new_delete.cpp.o"

# External object files for target operator_new
operator_new_EXTERNAL_OBJECTS =

new/operator_new: new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o
new/operator_new: new/CMakeFiles/operator_new.dir/build.make
new/operator_new: new/CMakeFiles/operator_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhoukang/projects/mygithub/ipc_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable operator_new"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/new && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/operator_new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
new/CMakeFiles/operator_new.dir/build: new/operator_new

.PHONY : new/CMakeFiles/operator_new.dir/build

new/CMakeFiles/operator_new.dir/requires: new/CMakeFiles/operator_new.dir/重载new_delete.cpp.o.requires

.PHONY : new/CMakeFiles/operator_new.dir/requires

new/CMakeFiles/operator_new.dir/clean:
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/new && $(CMAKE_COMMAND) -P CMakeFiles/operator_new.dir/cmake_clean.cmake
.PHONY : new/CMakeFiles/operator_new.dir/clean

new/CMakeFiles/operator_new.dir/depend:
	cd /home/zhoukang/projects/mygithub/ipc_demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhoukang/projects/mygithub/ipc_demo /home/zhoukang/projects/mygithub/ipc_demo/new /home/zhoukang/projects/mygithub/ipc_demo/build /home/zhoukang/projects/mygithub/ipc_demo/build/new /home/zhoukang/projects/mygithub/ipc_demo/build/new/CMakeFiles/operator_new.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : new/CMakeFiles/operator_new.dir/depend

