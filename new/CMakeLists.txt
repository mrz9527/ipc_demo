cmake_minimum_required(VERSION 3.5.1)
project(ipc_demo)

set(CMAKE_CXX_STANDARD 11)

# 重载new/delete
add_executable(operator_new 重载new_delete.cpp)