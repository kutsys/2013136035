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
    char p_id[BUF_SIZE]="2013136035";
    int  p_pid =getpid();
    char comm[BUF_SIZE];
    shm_id = shmget( (key_t)KEY_NUM,1024, IPC_CREAT| 0777);
    shm_addr = shmat( shm_id, ( void *)0, 0);
    printf("input start: ");
    scanf("%s",comm);
    if(!strcmp(comm,"start")){
    	sprintf( (char *)shm_addr, "%s %d\n", p_id,p_pid);
    	printf("producer : %s, %d\n",p_id, p_pid);
    	sleep(5);
    	printf("consumer : %s\n",(char*)shm_addr);
    }
    return 0;
}
