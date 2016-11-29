#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int status;
    pid_t pid;
    int i=0;
    int count = 0;
    printf("2013136035 Ra Hyun Ji \n");
    for(i=0; i<20; i++){
        pid = fork();
        if(pid){
           while(!waitpid(pid,&status,WNOHANG)){
           }
           if(WIFEXITED(status))
               count++;
           
        }
        else{
            execl("/home/hyunji/subproc","./subproc","20",NULL);
        }
    }

    if(count==20)
        printf("Finished (process)\n");
   
    return 0;
}

