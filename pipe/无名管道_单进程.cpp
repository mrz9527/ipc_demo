// author : zhoukang
// date   : 2022-05-19 20:06:18

/* linux platform*/

#include <unistd.h>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <csignal>

int fd[2] = {0};
char writebuf[]{"hello, linux"};
char readbuf[128]{0};

bool create_pipe() {
    int ret = pipe(fd);
    if(ret<0) {
        printf("create pipe failure, errno = %d\n", errno);
        return false;
    }
    return true;
}

// 关闭读，只写
// 异常，发送sigpipe信号
void closeread__write() {
    // 关闭读
    close(fd[0]);

    // 一直写
    int ret = -1;
    for(int i = 0; ; ++i) {
        // 读端关闭后，第一次写数据，就会异常，并发送sigpipe信号退出程序
        ret = write(fd[1], writebuf, sizeof(writebuf));
        if(ret < 0) {
            perror("write faild");
            break;
        } else {
            printf("写入次数 = %d，写入字节数 = %d\n", i+1, (i+1)*sizeof (writebuf));
        }
    }
    close(fd[1]);
}

// 读不关闭，不读只写
// 异常，发送sigpipe信号
void noread__write() {
    // 一直写
    int ret = -1;
    char ch[1] {'a'};
    for(int i = 0; ; ++i) {
        // 读端关闭后，第一次写数据，就会异常，并发送sigpipe信号退出程序
        ret = write(fd[1], ch, sizeof(ch));
        if(ret < 0) {
            perror("write faild");
            break;
        } else {
            printf("写入次数 = %d，写入字节数 = %d\n", i+1, (i+1)*sizeof (ch));
        }
    }
    close(fd[1]);
}

// 关闭写，只读
void closewrite_read() {
    close(fd[1]);

    int times = 0;
    while(true){
        memset(readbuf, 0, sizeof(readbuf));
        long ret = read(fd[0], readbuf, strlen(writebuf) + 1);
        if (ret <0) {
            perror("read 失败");
            return;
        }

        if (ret == 0) {
            printf("读取数据长度为0，准备退出\n");
            break;
        }

        printf("第%d次读数据, ret = %d, readbuf_len = %d, readbuf = %s\n", times, ret, strlen(readbuf), readbuf);
        ++times;
    }

    close(fd[0]);
}

// 写不关闭，且不写只读
void nowrite_read() {
    int times = 0;
    while(true){
        memset(readbuf, 0, sizeof(readbuf));
        long ret = read(fd[0], readbuf, strlen(writebuf) + 1);
        if (ret <0) {
            perror("read 失败");
            return;
        }

        if (ret == 0) {
            printf("读取数据长度为0，准备退出\n");
            break;
        }

        printf("第%d次读数据, ret = %d, readbuf_len = %d, readbuf = %s\n", times, ret, strlen(readbuf), readbuf);
        ++times;
    }

    close(fd[0]);
}

// 正常读写
void write_read() {
    // 向管道中写入数据
    write(fd[1], writebuf, sizeof(writebuf));

    // 从管道读取数据
    int read_size = read(fd[0], readbuf, sizeof(readbuf));
    printf("first read. read_size = %d, readbuf = %s\n", read_size, readbuf);

    printf("start: second read\n");
    read_size = -2;
    memset(readbuf, 0, sizeof(readbuf));

    alarm(2);
    auto func = [](int sig) ->void {
        printf("接收到信号%d\n", sig);
    };
    //signal(SIGALRM, func);

    auto sigHandler = [](int signum, siginfo_t * siginfo, void * arg)->void {
        printf("call sigHandler. sig = %d\n",signum);
    };
    struct sigaction act;
    act.sa_sigaction = sigHandler;
    act.sa_flags = /*SA_RESTART | */SA_SIGINFO;
    sigaction(SIGALRM, &act, nullptr);

    read_size = read(fd[0], readbuf, sizeof(readbuf));
    if(read_size <=0 && strlen(readbuf) == 0) {
        printf("second read failure\n");
    } else
        printf("second read. read_size = %d, readbuf = %s\n", read_size, readbuf);


    close(fd[0]);
}

int main() {
    // 创建管道文件
    create_pipe();

    // 假设io是阻塞的，没有设置O_NONBLOCK
    // 情形1：关闭读，只写。直接异常，发送sigpipe信号
    //closeread__write();

    // 情形2：读不关闭，不读只写。写满后会阻塞，缓冲长度为65536字节。
    //noread__write();

    // 情形3：关闭写，只读。第一次读取出来的长度为0，就像读到了文件尾一样
    //closewrite_read();

    // 情形4：写不关闭，不写只读，此时读会阻塞
    //nowrite_read();

    // 正常读写
    write_read();
    return 0;
}

