// author : zhoukang
// date   : 2022-05-19 20:06:18

#include <unistd.h> //pipe
#include <cstdio>   //printf
#include <cerrno>   //errno
#include <string>   //memset
#include <sys/types.h>   //mkfifo
#include <sys/stat.h>
#include <fcntl.h>

void doJob(const char* name) {
    for(int i = 0; i<5; ++i) {
        printf("%s %d\n", name, i);
        usleep(10);
    }
}

int main() {

    // 先执行进程A的业务
    doJob("processA");

    sleep(10);

    // 业务执行完毕后，通过向管道写数据，告知进程B
    int ret{-1};
    const char* fifo{"./myfifo"};
    if((access(fifo,F_OK))!=-1)
    {
        printf("%s 有名管道文件存在.\n", fifo);
    } else {
        printf("%s 有名管道文件不存在.\n", fifo);
        // 创建有名管道文件
        ret = mkfifo("./myfifo", 0777);
        if (ret<0){
            perror("有名管道文件创建失败");
            return -1;
        }
        printf("%s 有名管道文件创建成功.\n", fifo);
    }

    int fd = open(fifo, O_WRONLY);
    if(fd<0) {
        printf("打开有名管道文件失败:%s\n", fifo);
        return -1;
    }
    printf("打开有名管道文件成功:%s\n", fifo);

    char writebuf[1]{10};
    ret = write(fd, writebuf, sizeof(writebuf));
    if(ret < 0) {
        perror("写失败\n");
    }
    printf("写成功\n");

    while(1);

    return 0;
}

