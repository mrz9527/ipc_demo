// author : zhoukang
// date   : 2022-05-20 20:38:24

#include <cstdio>
#include <cstdlib>
#include <csignal>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork failure\n");
        return -1;
    }

    if(pid == 0) { // 子进程
        raise(SIGSTOP); // 让子进程暂停
        while (1);
    } else { // 父进程
        sleep(8);

        int ret = waitpid(pid, nullptr, WNOHANG);
        if(ret == 0) {
            printf("子进程%d暂未结束，通过命令来结束子进程，kill 9 %d\n", pid, pid);
            kill(pid, 9);
        }

        wait(nullptr);

        while (1);
    }

    return 0;
}
