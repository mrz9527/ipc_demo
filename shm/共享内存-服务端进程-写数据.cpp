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
    char buf[124];
};

auto sigHandler = [](int sig)->void {
    return;
};

int main(int argc, char **argv)
{
    // 创建共享内存
    int shm_id = -1;
    shm_id = create_shm_by_ftok();
    if(shm_id == -1) {
        perror("服务端创建共享内存失败");
        return -1;
    }

    // 共享内存映射
    struct shm_buffer* shmbuf = (struct shm_buffer*)shmat(shm_id, nullptr, 0);
    if(shmbuf == (shm_buffer*)-1) {
        perror("服务端 : shmat(shm_id, nullptr, 0) failed");
        return -2;
    }

    // 设置信号处理函数
    signal(SIGUSR2, sigHandler);

    // 交互进程号
    // 向共享内存写数据
    shmbuf->pid = getpid();
    // 阻塞自己，等待客户端来唤醒自己
    pause();
    // 获取客户端进程pid号
    pid_t client_pid = shmbuf->pid;

    // 正常通信
    while(1) {
        // 1. 写数据到共享内存
        printf("server write :");
        memset(shmbuf, 0, SHM_SIZE);
        fgets(shmbuf->buf, sizeof(shmbuf->buf), stdin);
        // 2. 告知客户端进程
        kill(client_pid, SIGUSR1);
        // 3. 等待客户端进程处理
        pause();
    }

    shmdt(shmbuf);
    shmctl(shm_id, IPC_RMID, nullptr);

    return 0;
}

