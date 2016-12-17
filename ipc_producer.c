#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO_NAME "/tmp/my_fifo"
#define BUF_SIZE 1024
int main(){

    char p_id[BUF_SIZE]="2013136035";
    int  p_pid =getpid(); 
    char c_id[BUF_SIZE];
    int c_pid; 
    int len;
    char start[10];
    int pipe_id,res;

    printf("input start: ");
    scanf("%s",start);
    if(!strcmp(start,"start")){
        if(access(FIFO_NAME, F_OK)== -1){
            res = mkfifo("/tmp/my_fifo", 0777);
            if (res != 0) exit(EXIT_FAILURE);
        }
        pipe_id = open(FIFO_NAME, O_RDWR|O_TRUNC);
	write(pipe_id,&p_pid,4);        
	write(pipe_id,p_id,strlen(p_id)+1);
 	printf("produser: %s, %d\n",p_id,p_pid);
        sleep(3);
	read(pipe_id,&c_pid,4);
        len = read(pipe_id,c_id,BUF_SIZE);
	c_id[len]=0;
        
        printf("consumer: %s, %d\n",c_id,c_pid);
    }
    return 0;
}

