// author : zhoukang
// date   : 2022-05-24 18:23:57

#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <cstdlib>

bool file_exists(const char *filename)
{
    return (access(filename, F_OK) == 0);
}

bool create_file(const char* filenname) {
    int fd = open(filenname, O_CREAT|O_RDWR, 0777);
    if(fd < 0) {
        return false;
    }
    close(fd);
    return true;
}

// IPC_PRIVATE方式创建共享内存
int create_sem_by_private(int nsems = 3, int shmflg = 0777) {
    // 创建共享内存
    return semget(IPC_PRIVATE, nsems, shmflg);
}

int create_sem_by_ftok(const char* pathname = "./1.txt", int proj_id = 'a', int nsems = 3, int shmflg = IPC_CREAT | 0777) {
    // 创建IPC key
    if((!file_exists(pathname)) &&
    (!create_file(pathname))) { // 文件不存在，且创建文件失败
        return -1;
    }

    key_t ipc_key = ftok(pathname, proj_id);
    if(ipc_key == -1) {
        return -1;
    }

    return semget(ipc_key, nsems, shmflg);
}

void rm_sem(int semid) {
    // 删除信号灯集时，只有3个参数，且第二个参数可以随意填0~nsems-1中的一个，一般填0，
    semctl(semid, 0, IPC_RMID);
}

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
};

// 打印信号灯集中某个信号灯的值
// 当semnum = -1时，打印所有信号灯的值
void print_sem_value(int semid, int semnum) {
    if(semnum == -1) {
        unsigned short val[3] {0}; // 总共3个信号灯
        semctl(semid, semnum, GETALL, val);
        printf("val0:%d, val1:%d, val2:%d\n", val[0], val[1], val[2]);
    } else {
        int value = semctl(semid, semnum, GETVAL);

        printf("val%d:%d\n", semnum, value);
    }
}

int main(int argc, char**argv) {
    int nsems = 3;
    // 1.创建信号灯集
    //int sem_id = create_sem_by_private();
    int sem_id = create_sem_by_ftok("./1.txt", 'a', nsems, IPC_CREAT | 0666);
    printf("sem_id = %d\n", sem_id);

    printf("temp = %d\n", semctl(sem_id, 0, GETNCNT));

    unsigned short valueArr[3] {2,5,1}; // 第0个信号灯初值为2，第一个信号灯初值为5，第二个信号灯初值为1
    union semun sem_init_values;
    sem_init_values.array = valueArr;
    // 2. 初始化信号灯集
    semctl(sem_id, 0, SETALL, sem_init_values);

    // 3. 打印所有信号灯的值
    print_sem_value(sem_id, -1);

    for (int i = 0; i < nsems; ++i) {
        print_sem_value(sem_id, i);
    }

    // 4. 释放编号为2的信号灯3个资源。
    printf("释放编号为2的信号灯3个资源。\n");
    struct sembuf sem_buf = {2, 3, 0};
    semop(sem_id, &sem_buf, 1);
    print_sem_value(sem_id, -1);

    print_sem_value(sem_id, 2);

    // 4. 请求编号为0的信号灯1个资源，请求编号为1的信号灯3个资源
    printf("请求编号为0的信号灯一个资源，请求编号为1的信号灯3个资源。\n");
    struct sembuf sem_buf01[2] {
            {0, -1, 0},
            {1, -3, 0}
    };
    semop(sem_id, sem_buf01, sizeof(sem_buf01)/sizeof(sem_buf01[0]));
    print_sem_value(sem_id, -1);

    // 4. 请求编号为2的信号灯4个资源
    printf("请求编号为2的信号灯4个资源。\n");
    sem_buf.sem_op = -4;
    semop(sem_id, &sem_buf, 1);
    print_sem_value(sem_id, -1);


    int xxx = 0;
    int yyy = semctl(sem_id, 0, GETNCNT, &xxx);
    printf("GETNCNT: xxx = %d, yyy = %d\n", xxx, yyy);

    xxx = 0;
    yyy = semctl(sem_id, 0, GETZCNT, &xxx);
    printf("GETZCNT: xxx = %d, yyy = %d\n", xxx, yyy);


    // 4. 请求编号为2的信号灯1个资源
    printf("请求编号为2的信号灯1个资源。\n");
    sem_buf.sem_op = -1;
    semop(sem_id, &sem_buf, 1);
    print_sem_value(sem_id, -1);

    // 4. 请求编号为2的信号灯1个资源
    printf("请求编号为2的信号灯1个资源。\n");
    sem_buf.sem_op = -1;
    semop(sem_id, &sem_buf, 1);
    print_sem_value(sem_id, -1);



    // 删除信号灯集
    rm_sem(sem_id);


    return 0;
}

