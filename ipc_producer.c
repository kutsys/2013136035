#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO_NAME "/tmp/my_fifo"
#define BUF_SIZE 11
int main(){

    char p_id[BUF_SIZE]="2013136035";
    int  p_pid =getpid(); 
    char c_id[BUF_SIZE];
    int c_pid;
    char start[10];
    int pipe_id,res;
    printf("please input start:");
    scanf("%s",start);
    if(start){
        if(access(FIFO_NAME, F_OK)== -1){
            res = mkfifo("/tmp/my_fifo", 0777);
            if (res != 0) exit(EXIT_FAILURE);
        }
        pipe_id = open(FIFO_NAME, O_RDWR|O_TRUNC);
        write(pipe_id,p_id,BUF_SIZE);
        write(pipe_id,&p_pid,4);
        sleep(3);
        read(pipe_id,c_id,BUF_SIZE-1);
        read(pipe_id,&c_pid,4);
        printf("produser: %s, %d\n",p_id,p_pid);
        printf("consumer: %s, %d\n",c_id,c_pid);
    }
    return 0;
}

