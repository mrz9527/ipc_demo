// author : zhoukang
// date   : 2022-05-19 20:06:18

/* 无名管道，有亲缘关系的父子进程通信
 * 通过管道方式，实现父进程先运行，子进程后运行
 * */

#include <unistd.h>
#include <cstdio>
#include <cerrno>

int main()
{
    // 创建管道
    int fd[2];
    int ret = pipe(fd);
    if (ret < 0) {
        perror("pipe(fd) failure");
        return -1;
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failure");
        return -1;
    }

    if (pid == 0) {
        // 子进程
        //
        close(fd[1]); // 子进程中只读，关闭写描述符（父进程中已经存在写描述符，所以可以关闭子进程写描述符）

        char val = 0;
        while(val != 5) {
            read(fd[0], &val, 1);
        }
        for (int i = 0; i < 4; ++i) {
            printf("child process[%d] do job %d\n", getpid(), i);
            usleep(100);
        }

    } else {
        // 父进程
        close(fd[0]); // 父进程中只写，关闭读描述符（子进程中已经存在读描述符，所以可以关闭父进程读描述符）

        for (int i = 0; i < 5; ++i) {
            printf("parent process[%d] do job %d\n", getpid(), i);
            usleep(100);
        }

        sleep(3);
        char val = 5;
        write(fd[1], &val, 1);

        while (1); // 不让父进程退出
    }

    return 0;

}

