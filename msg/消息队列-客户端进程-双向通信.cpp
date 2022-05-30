// author : zhoukang
// date   : 2022-05-23 22:46:28

#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstdio>
#include <cstring>
#include <unistd.h>

/* 多进程方式实现
 * 一个进程写，一个进程读
 * */

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

struct msgbuffer
{
    long int msg_type;
    char buf[1];
};

int main(int argc, char** argv) {
    // 创建消息队列
    int msg_id = create_msg_by_ftok();
    if(msg_id<0) {
        perror("create_msg_by_ftok failed");
        return -1;
    }

    struct msgbuffer buf {0};
    int buf_buf_len = 124;

    pid_t pid = fork();
    if(pid > 0) {
        // 父进程写 200
        buf.msg_type = 200;
        while(1) {
            memset(buf.buf, 0, sizeof(buf.buf));
            fgets(buf.buf, buf_buf_len, stdin);
            msgsnd(msg_id, &buf, strlen(buf.buf) + 1, 0);
            printf("客户端发送: %s\n", buf.buf);
        }
        
    } else if(pid == 0){
        // 子进程读 100
        int msg_type = 100;
        while(1) {
            memset(buf.buf, 0, sizeof(buf.buf));
            msgrcv(msg_id, &buf, buf_buf_len, msg_type, 0);
            printf("服务端接收:%s\n", buf.buf);
        }
    }

    return 0;
}
