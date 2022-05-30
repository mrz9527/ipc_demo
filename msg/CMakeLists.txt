cmake_minimum_required(VERSION 3.5.1)
project(ipc_demo)

set(CMAKE_CXX_STANDARD 11)

# 共享内存
add_executable(msg_server_rw 消息队列-服务端进程-双向通信.cpp)
add_executable(msg_client_rw 消息队列-客户端进程-双向通信.cpp)
