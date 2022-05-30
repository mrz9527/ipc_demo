cmake_minimum_required(VERSION 3.5.1)
project(ipc_demo)

set(CMAKE_CXX_STANDARD 11)

# 信号通信
## kill
add_executable(sendSignal_kill 信号发送_kill.cpp)
## raise
add_executable(sendSignal_raise 信号发送_raise.cpp)
add_executable(sendSignal_raise_stopprocess 信号发送_raise_暂停进程.cpp)
## alarm
add_executable(sendSignal_alarm 信号发送_alarm.cpp)
