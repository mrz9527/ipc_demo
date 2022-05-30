// author : zhoukang
// date   : 2022-05-21 14:10:30

#include <cstdio>
#include <string>
#include <unistd.h>
#include <csignal>

#define printLog(format, args...) printf("%s\t" format, getSysTime().c_str(), ##args)

std::string getSysTime(const char* format = "%Y-%m-%d %H:%M:%S") {
    time_t t = time(0);
    struct tm *lt = localtime(&t);
    char timebuf[128] {0};
    strftime(timebuf, sizeof(timebuf), format, lt);
    return timebuf;
}

void timerHandler (int sig) {
    printLog("sig = %d\n", sig);
}

int main() {
    printLog("start main\n");

    // alarm定时器，设置定时时间和回调函数（这里指的是信号处理函数）
    alarm(3);
    signal(SIGALRM, timerHandler);

    // 等待信号的触发
    while(1);

    return 0;
}
