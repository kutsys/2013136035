#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZE 1024
#define FIFO_NAME "/tmp/my_fifo"
int main(){
    char p_id[BUF_SIZE];
    int p_pid;
    int len;
    char c_id[BUF_SIZE-1] = "hyunji Ra";
    int c_pid = getpid();
    int pipe_id,res;

    if(access(FIFO_NAME, F_OK)== -1) { 
        res = mkfifo("/tmp/my_fifo", 0777);
        if (res != 0) exit(EXIT_FAILURE);
    
    }

    	pipe_id = open(FIFO_NAME,O_RDWR);
	read(pipe_id,&p_pid,4);
    	len = read(pipe_id,p_id,BUF_SIZE);
	p_id[len] = 0;
	
  
    	printf("        producer : %s, %d\n",p_id,p_pid);
    	printf("            send : %s, %d\n",c_id,c_pid);	
	write(pipe_id,&c_pid,4);    
    	write(pipe_id,c_id,strlen(c_id)+1);
    	
        
return 0;
}
