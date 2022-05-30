// author : zhoukang
// date   : 2022-05-22 17:24:07

#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstdio>
#include <unistd.h>
#include <csignal>
#include <cstring>

#define SHM_SIZE 128

int create_shm_by_ftok(const char* pathname = "./1.txt", int proj_id = 'a', size_t size = SHM_SIZE, int shmflg = IPC_CREAT | 0777) {
    // 创建IPC key
    key_t ipc_key = ftok(pathname, proj_id);
    if(ipc_key == -1) {
        printf("ftok(\"%s\", %d) failed\n", pathname, proj_id);
        perror("errorMsg:");
        return -1;
    }

    return shmget(ipc_key, size, shmflg);
}

struct shm_buffer {
    pid_t pid;
    char buf[124] {0};
};

auto sigHandler = [](int sig)->void {
    return;
};

int main(int argc, char **argv)
{
    // 设置信号处理函数
    signal(SIGUSR1, sigHandler);

    // 打开共享内存
    int shm_id = -1;
    shm_id = create_shm_by_ftok("./1.txt", 'a', SHM_SIZE, 0777);
    if(shm_id == -1) {
        perror("客户端打开共享内存失败");
        return -1;
    }

    // 共享内存映射
    struct shm_buffer* shmbuf = (struct shm_buffer*)shmat(shm_id, nullptr, 0);
    if(shmbuf == (shm_buffer*)-1) {
        perror("客户端 : shmat(shm_id, nullptr, 0) failed");
        return -2;
    }

    // 获取服务端进程号
    pid_t server_pid = shmbuf->pid;
    // 向共享内存写入自己的进程号
    shmbuf->pid = getpid();

    kill(server_pid, SIGUSR2);

    while(1) {
        // 1. 等待服务端进程通知
        pause();
        // 2. 读数据
        printf("client read: %s", shmbuf->buf);
        // 2. 告知服务端进程
        kill(server_pid, SIGUSR2);
    }

    shmdt(shmbuf);

    return 0;
}

