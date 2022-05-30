cmake_minimum_required(VERSION 3.5.1)
project(ipc_demo)

set(CMAKE_CXX_STANDARD 11)

# 定时器
## alarm
add_executable(timer_alarm 定时器_alarm.cpp)
add_executable(timer_setitimer 定时器_setitimer.cpp)
