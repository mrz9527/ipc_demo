// author : zhoukang
// date   : 2022-05-23 22:46:28

#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <csignal>
#include <cstdlib>

/* 多进程方式实现
 * 一个进程写，一个进程读
 * */

int msg_id = -1;

int create_msg_by_private(int msgflg = 0666) {
    return msgget(IPC_PRIVATE, msgflg);
}

int create_msg_by_ftok(const char* pathname = "./1.txt", int proj_id = 'a', int shmflg = IPC_CREAT | 0666) {
    // 创建IPC key
    key_t ipc_key = ftok(pathname, proj_id);
    if(ipc_key == -1) {
        return -1;
    }

    return msgget(ipc_key, shmflg);
}

int rm_msg(int msgid) {
    return msgctl(msgid, IPC_RMID, nullptr);
}

void exitHandler(int sig) {
    if(sig == 2 || sig == 9 || sig == 15) {
        printf("接收信号signum = %d，清理并退出程序.\n", sig);
        msgctl(msg_id, IPC_RMID, nullptr);
        exit(0);
    }
}

struct msgbuffer
{
    long int msg_type;
    char buf[1];
};

int main(int argc, char** argv) {
    // 创建消息队列
    msg_id = create_msg_by_ftok();
    if(msg_id <0) {
        perror("create_msg_by_ftok failed");
        return -1;
    }
    struct msgbuffer buf {0};
    int buf_buf_len = 124;

    pid_t pid = fork();
    if(pid > 0) {
        signal(SIGCHLD, SIG_IGN); // 避免僵尸进程
        signal(2, exitHandler);
        signal(9, exitHandler);
        signal(15, exitHandler);
        // 父进程写 100
        buf.msg_type = 100;
        while(1) {
            memset(buf.buf, 0, sizeof(buf.buf));
            fgets(buf.buf, buf_buf_len, stdin);
            msgsnd(msg_id, &buf, strlen(buf.buf)+1, 0);
            printf("服务端发送: %s\n", buf.buf);
        }

        // 释放消息队列
        rm_msg(msg_id);

    } else if(pid == 0){
        signal(2, exitHandler);
        signal(9, exitHandler);
        signal(15, exitHandler);
        // 子进程读 200
        int msg_type = 200;
        while(1) {
            memset(buf.buf, 0, sizeof(buf.buf));
            msgrcv(msg_id, &buf, buf_buf_len, msg_type, 0);
            printf("服务端接收:%s\n", buf.buf);
        }
    }

    return 0;
}
