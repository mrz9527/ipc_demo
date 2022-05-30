cmake_minimum_required(VERSION 3.5.1)
project(ipc_demo)

set(CMAKE_CXX_STANDARD 11)

# 共享内存
add_executable(shm_create 共享内存-创建.cpp)
add_executable(shm_parent_child_process 共享内存-父子进程通信.cpp)

# 单向通信
# 服务端写数据，客户端读数据
add_executable(shm_client_read 共享内存-客户端进程-读数据.cpp)
add_executable(shm_server_write 共享内存-服务端进程-写数据.cpp)

# 双向通信
# 服务端读写，客户端读写
add_executable(shm_client_rw 共享内存-客户端进程-双向通信.cpp)
add_executable(shm_server_rw 共享内存-服务端进程-双向通信.cpp)
target_link_libraries(shm_client_rw pthread)
target_link_libraries(shm_server_rw pthread)