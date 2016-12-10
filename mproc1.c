#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int status;
    pid_t pid[10];
    int i=0;
    int count = 0;
    printf("2013136035 Ra Hyun Ji \n");
    for(i=0; i<10; i++){
        pid[i] = fork();
        if(pid[i]){
      
           
        }
        else{
            execl("/home/hyunji/subproc","./subproc","20",NULL);
        }
    }

    for(i=0; i<10; i++){

        while(!waitpid(pid[i],&status,WNOHANG)){
              }
    }
    if(WIFEXITED(status))
        count++;
    if(count==20)
        printf("Finished (process)\n");
   
    return 0;
}

