cmake_minimum_required(VERSION 3.5.1)
project(ipc_demo)

set(CMAKE_CXX_STANDARD 11)

# 无名管道
add_executable(noname_pipe_oneprocess 无名管道_单进程.cpp)
add_executable(noname_pipe_multiprocess 无名管道_多进程.cpp)

#有名管道
add_executable(name_pipe_processA_write 有名管道_多进程之进程A.cpp)
add_executable(name_pipe_processB_read 有名管道_多进程之进程B.cpp)