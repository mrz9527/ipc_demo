// author : zhoukang
// date   : 2022-05-22 17:24:07

#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

// IPC_PRIVATE方式创建共享内存
int create_shm_by_private(size_t size = 128, int shmflg = 0777) {
    // 创建共享内存
    return shmget(IPC_PRIVATE, size, shmflg);
}

int create_shm_by_ftok(const char* pathname = "./1.txt", int proj_id = 'a', size_t size = 128, int shmflg = IPC_CREAT | 0777) {
    // 创建IPC key
    key_t ipc_key = ftok(pathname, proj_id);
    if(ipc_key == -1) {
        return -1;
    }

    printf("ipc_key = %X\n", ipc_key);

    return shmget(ipc_key, size, shmflg);
}

int main(int argc, char **argv)
{
    int shm_id = -1;
    // 方式1：IPC_PRIVATE方式创建共享内存
    //shm_id = create_shm_by_private();

    // 方式2：基于ftok方式创建共享内存
    shm_id = create_shm_by_ftok();

    printf("shm_id = %d\n", shm_id);
    if(shm_id == -1) {
        perror("创建共享内存失败");
        return -1;
    }

    system("ipcs -m");
    return 0;
}

