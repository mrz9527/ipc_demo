// author : zhoukang
// date   : 2022-05-22 17:24:07

/* 要点：一个进程pause()，可以通过信号来唤醒线程。
 *      一个子线程pause()，其他线程运行。如果收到信号，可能其他线程被立马打断，也可能被pause()的线程被唤醒，具有不确定性。
 *      而且被pause的线程处于阻塞状态，可能暂时没有获取cpu，而其他线程拥有cpu时间片，更容易捕获信号。
 *
 *      主线程main中，为了不让程序退出，有一个while(1)死循环，子线程readThread中，为了等待服务端通知共享内存可读，有一个pause()。
 *      现在服务端发送信号过来，可能打断主线程while(1)死循环，也有可能打断pause()，所以存在缺陷。
 *
 *      所以，在多线程中，可能不适合使用pause()函数。
 *
 *      解决办法：去掉pause(),而是换成条件变量cond.wait()，信号不会打算cond.wait()，只能打断while(1)，然后再信号处理函数中cond.notify,
 *      来唤醒读线程。
 * */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstdio>
#include <unistd.h>
#include <csignal>
#include <cstring>
#include <mutex>
#include <semaphore.h>

#define SHM_SIZE 4096

pid_t client_pid = 0;
sem_t sem;
int rshmid, wshmid;

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
    char buf[SHM_SIZE-4];
    pid_t pid;
};

// 拥有获取对端的进程号，整个程序运行期间只使用一次
auto sigObtainPidHandler = [](int sig)->void {
    //printf("sigObtainPidHandler. 收到信号\n");
    return;
};

auto sigReadBufHandler = [](int sig)->void{
    // 释放信号量，信号量的值+1
    //printf("sigReadBufHandler. 收到信号\n");
    sem_post(&sem);
    //printf("sigReadBufHandler. 释放信号量\n");
    return;
};

void* readThread(void* arg) {
    pthread_detach(pthread_self());
    struct shm_buffer* rshmbuf = (struct shm_buffer*)arg;

    while(1) {
        // 1. 等待客户端端进程通知
        //pause(); // 不使用pause
        //printf("readThread.sem_wait阻塞中\n");
        sem_wait(&sem);
        //printf("readThread. 获取信号量\n");
        // 2. 读数据
        printf("[服务端接收][shmid = %d]: %s\n", rshmid, rshmbuf->buf);
    }

    return nullptr;
}

void* writeThread(void* arg) {
    pthread_detach(pthread_self());
    struct shm_buffer* wshmbuf = (struct shm_buffer*)arg;
    // 正常通信
    while(1) {
        // 1. 写数据到共享内存
        //memset(wshmbuf->buf, 0, SHM_SIZE-4); // 不知道为什么不能使用memset，反正使用之后，共享内存数据为空
        fgets(wshmbuf->buf, sizeof(wshmbuf->buf), stdin);
        printf("[服务端发送][shmid = %d]: %s\n", wshmid, wshmbuf->buf);
        // 2. 告知客户端进程
        kill(client_pid, SIGUSR1);
    }
    return nullptr;
}
int main(int argc, char **argv)
{
    // 初始化0，可以用作同步
    sem_init(&sem, 0, 0);

    // 创建共享内存1、2
    int rshm_id = create_shm_by_ftok("./1.txt", 'r',  SHM_SIZE, IPC_CREAT | 0777);
    int wshm_id = create_shm_by_ftok("./1.txt", 'w',  SHM_SIZE, IPC_CREAT | 0777);

    rshmid = rshm_id;
    wshmid = wshm_id;

    if(rshm_id == -1 || wshm_id == -1) {
        return -1;
    }

    // 共享内存映射1、2
    struct shm_buffer* rshmbuf = (struct shm_buffer*)shmat(rshm_id, nullptr, 0);
    struct shm_buffer* wshmbuf = (struct shm_buffer*)shmat(wshm_id, nullptr, 0);
    if(rshmbuf == (shm_buffer*)-1 || wshmbuf == (shm_buffer*)-1) {
        return -2;
    }

    // 交互进程号
    // 设置信号处理函数
    signal(SIGUSR2, sigObtainPidHandler);
    // 向共享内存写数据
    wshmbuf->pid = getpid();
    // 阻塞自己，等待客户端来唤醒自己
    pause();
    // 获取客户端进程pid号
    client_pid = wshmbuf->pid;

    signal(SIGUSR2, sigReadBufHandler);

    pthread_t tid[2];
    pthread_create(&tid[0], nullptr, readThread, (void*)rshmbuf);
    pthread_create(&tid[0], nullptr, writeThread, (void*)wshmbuf);

    while(1);

    shmdt(rshmbuf);
    shmctl(rshm_id, IPC_RMID, nullptr);

    shmdt(wshmbuf);
    shmctl(wshm_id, IPC_RMID, nullptr);

    return 0;
}

