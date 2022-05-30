// author : zhoukang
// date   : 2022-05-22 17:24:07

#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstdio>
#include <unistd.h>
#include <csignal>
#include <cstring>

#define SHM_SIZE 128

// IPC_PRIVATE方式创建共享内存
int create_shm_by_private(size_t size = SHM_SIZE, int shmflg = 0777) {
    // 创建共享内存
    return shmget(IPC_PRIVATE, size, shmflg);
}

int main(int argc, char **argv)
{
    int shm_id = -1;
    // 方式1：IPC_PRIVATE方式创建共享内存
    shm_id = create_shm_by_private();
    if(shm_id == -1) {
        perror("创建共享内存失败");
        return -1;
    }

    printf("shm_id = %d\n", shm_id);

    auto sigHandler = [](int sig)->void {
        return;
    };

    char* shmaddr;
    // 共享内存映射
    shmaddr = (char*)shmat(shm_id, nullptr, 0);
    if(shmaddr == nullptr) {
        perror("parent process : shmat(shm_id, nullptr, 0) failed");
        return -2;
    }

    // 创建子进程
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork() failed");
        return -1;
    }

    if (pid == 0) {
        // 设置信号处理函数
        signal(SIGUSR1, sigHandler);

        while(1) {
            // 1. 等待父进程通知
            pause();
            // 2. 读数据
            printf("child process read share data: %s\n", shmaddr);
            // 2. 告知父进程
            kill(getppid(), SIGUSR2);
        }

    } else if(pid > 0){
        // parent process

        // 设置信号处理函数
        signal(SIGUSR2, sigHandler);

        while(1) {
            // 1. 发送数据/写数据到共享内存
            printf("parent process write share data:\n");
            scanf("%s", shmaddr);
            // 2. 告知子进程
            kill(pid, SIGUSR1);
            // 3. 等待子进程处理
            pause();
        }
    }

    shmdt(shmaddr);
    shmctl(shm_id, IPC_RMID, nullptr);

    return 0;
}

