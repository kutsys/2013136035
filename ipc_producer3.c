#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define  BUFF_SIZE   1024

typedef struct {
       int  pid;
       char* sid;
       char buff[BUFF_SIZE];
} t_data;

int main(){
    int      msqid;
    t_data   data;
    msqid = msgget( (key_t)1234, IPC_CREAT | 0777);
    data.pid = getpid();
    data.sid = "2013136035";
    char start[10];

    printf("input start : ");
    scanf("%s",start);
    if(!strcmp(start,"start")){
        sprintf( data.buff, "producer: pid=%d, sid=%s", data.pid,data.sid);
        msgsnd( msqid, &data, sizeof( t_data),0);
        printf("  send : %s\n",data.buff);

        sleep(5);
        msgrcv( msqid, &data, sizeof( t_data), 0, 0);
        printf("receive: %s\n", data.buff);

    }
    return 0;
}
