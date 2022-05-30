// author : zhoukang
// date   : 2022-05-21 14:10:30

#include <cstdio>
#include <string>
#include <unistd.h>
#include <csignal>
#include <sys/time.h>

//#define printLog(format, args...) printf("%s\t" format, getSysTime().c_str(), ##args)
//
//std::string getSysTime(const char* format = "%Y-%m-%d %H:%M:%S") {
//    time_t t = time(0);
//    struct tm *lt = localtime(&t);
//    char timebuf[128] {0};
//    strftime(timebuf, sizeof(timebuf), format, lt);
//    return timebuf;
//}
//
//void timerHandler (int sig) {
//    printLog("sig = %d\n", sig);
//}
//
//int main() {
//    printLog("start main\n");
//
//    // 延迟5秒发送SIGALRM信号，之后每间隔1秒发送一次SIGALRM信号
//    struct itimerval itimer;
//    itimer.it_interval.tv_sec = 1;
//    itimer.it_interval.tv_usec = 0;
//    itimer.it_value.tv_sec = 5;
//    itimer.it_value.tv_usec = 0;
//    setitimer(ITIMER_REAL, &itimer, nullptr);
//    signal(SIGALRM, timerHandler);
//
//    // 等待信号的触发
//    while(1);
//
//    return 0;
//}


void settime(int signum)
{
    printf("begin dingshi\n");
    printf("signum=%d\n",signum);
    sleep(1);
}
int main()
{
    signal(SIGALRM,settime);
    alarm(2);
    while(1)
    {
        int i=1;
        printf("i=%d\n",i);
    }
    return 0;
}