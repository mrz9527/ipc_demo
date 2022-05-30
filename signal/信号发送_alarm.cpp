// author : zhoukang
// date   : 2022-05-20 20:38:24

#include <cstdio>
#include <cstdlib>
#include <csignal>
#include <unistd.h>
#include <time.h>
#include <string>

std::string getTime() {
    time_t t;
    struct tm *tmp;
    char timebuf[128];

    /* 获取时间 */
    time(&t);
    tmp = localtime(&t);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tmp);
    return timebuf;
}

void printTime() {
    printf("%s\n", getTime().c_str());
}

void exitHandler (int sig) {
    printf("%s call exitHandler, sig = %d\n", getTime().c_str(), sig);
    exit(0);
}

void printHandler(int sig) {
    printf("%s call printHandler, sig = %d\n", getTime().c_str(), sig);
}

void alarmHandler(int sig) {
    printf("%s call alarmHandler, sig = %d\n", getTime().c_str(), sig);
}

int main(int argc, char** argv) {
    printf("%s start main\n", getTime().c_str());

    for(int i = 0; i<65; ++i) {
        if(i == 15) {
            signal(i, exitHandler);
        } else if(i == 14) {
            signal(i, alarmHandler);
        } else {
            signal(i, printHandler);
        }
    }

    alarm(10); // 设置定时10秒

    int i = 0;
    while(1) {
        pause();
        printf("%s doJob %d\n", getTime().c_str(), i);
        ++i;
    }

    return 0;
}
