#include <stdio.h>      // printf()
#include <unistd.h>     // sleep()
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define  KEY_NUM 1234
#define BUF_SIZE 1024
int main(){


    int   shm_id;
    void *shm_addr;
    char c_id[BUF_SIZE]="hyunji Ra";
    int  c_pid =getpid();
    char comm[BUF_SIZE];
    shm_id = shmget( (key_t)KEY_NUM,1024, IPC_CREAT| 0777);
    shm_addr = shmat( shm_id, ( void *)0, 0);
    scanf("%s",comm);
    printf("************please if program exit, input 'end'************\n");
    printf( "receive: %s\n", (char *)shm_addr);
    sprintf( (char *)shm_addr, "%s %d",c_id,c_pid);
    printf("    send: %s %d\n",c_id,c_pid);

}
