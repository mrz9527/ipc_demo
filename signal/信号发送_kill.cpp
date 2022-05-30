// author : zhoukang
// date   : 2022-05-20 20:38:24

#include <cstdio>
#include <cstdlib>
#include <csignal>

int main(int argc, char** argv) {
    if(argc<3) {
        printf("usage: mykill signum pid\n");
        return -1;
    }

    int signum = atoi(argv[1]);
    int pid = atoi(argv[2]);

    int ret = kill(pid, signum);
    if(ret<0){
        perror("kill failure\n");
        return -2;
    }

    return 0;
}
