// author : zhoukang
// date   : 2022-05-20 20:38:24

#include <cstdio>
#include <cstdlib>
#include <csignal>
#include <unistd.h>

int main(int argc, char** argv) {
    // printf是c++标准库函数，存在io缓冲，属于行缓冲。
    // 输出\n时，缓冲区会刷新，缓冲区数据发送给内核，由内核负责输出
    // 没有输出\n时，缓冲区数据不发送给内核
    printf("before raise(9) 1\n");  // 会输出。
    printf("before raise(9) 2"); // 不会输出

    // raise(9)会使得进程退出，退出前不会刷新io缓冲区到内核
    // exit(0)会使得进程退出，退出前会刷新io缓冲区到内核
    // _exit(0)会使得进程退出，退出前不会刷新io缓冲区到内核，同raise(9)
    raise(9);
    printf("after raise(9)\n"); // 不会输出

    return 0;
}
