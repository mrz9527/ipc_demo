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
include shm/CMakeFiles/shm_client_read.dir/depend.make

# Include the progress variables for this target.
include shm/CMakeFiles/shm_client_read.dir/progress.make

# Include the compile flags for this target's objects.
include shm/CMakeFiles/shm_client_read.dir/flags.make

shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o: shm/CMakeFiles/shm_client_read.dir/flags.make
shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o: ../shm/共享内存-客户端进程-读数据.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoukang/projects/mygithub/ipc_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/shm && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o -c /home/zhoukang/projects/mygithub/ipc_demo/shm/共享内存-客户端进程-读数据.cpp

shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.i"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/shm && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoukang/projects/mygithub/ipc_demo/shm/共享内存-客户端进程-读数据.cpp > CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.i

shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.s"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/shm && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoukang/projects/mygithub/ipc_demo/shm/共享内存-客户端进程-读数据.cpp -o CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.s

shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o.requires:

.PHONY : shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o.requires

shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o.provides: shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o.requires
	$(MAKE) -f shm/CMakeFiles/shm_client_read.dir/build.make shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o.provides.build
.PHONY : shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o.provides

shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o.provides.build: shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o


# Object files for target shm_client_read
shm_client_read_OBJECTS = \
"CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o"

# External object files for target shm_client_read
shm_client_read_EXTERNAL_OBJECTS =

shm/shm_client_read: shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o
shm/shm_client_read: shm/CMakeFiles/shm_client_read.dir/build.make
shm/shm_client_read: shm/CMakeFiles/shm_client_read.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhoukang/projects/mygithub/ipc_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable shm_client_read"
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/shm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shm_client_read.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
shm/CMakeFiles/shm_client_read.dir/build: shm/shm_client_read

.PHONY : shm/CMakeFiles/shm_client_read.dir/build

shm/CMakeFiles/shm_client_read.dir/requires: shm/CMakeFiles/shm_client_read.dir/共享内存-客户端进程-读数据.cpp.o.requires

.PHONY : shm/CMakeFiles/shm_client_read.dir/requires

shm/CMakeFiles/shm_client_read.dir/clean:
	cd /home/zhoukang/projects/mygithub/ipc_demo/build/shm && $(CMAKE_COMMAND) -P CMakeFiles/shm_client_read.dir/cmake_clean.cmake
.PHONY : shm/CMakeFiles/shm_client_read.dir/clean

shm/CMakeFiles/shm_client_read.dir/depend:
	cd /home/zhoukang/projects/mygithub/ipc_demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhoukang/projects/mygithub/ipc_demo /home/zhoukang/projects/mygithub/ipc_demo/shm /home/zhoukang/projects/mygithub/ipc_demo/build /home/zhoukang/projects/mygithub/ipc_demo/build/shm /home/zhoukang/projects/mygithub/ipc_demo/build/shm/CMakeFiles/shm_client_read.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : shm/CMakeFiles/shm_client_read.dir/depend

