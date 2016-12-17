#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#define BUF_SIZE 1024
void error_handling(char *message);
void error_handling(char *message)
{
        fputs(message, stderr);
        fputc('\n', stderr);
        exit(1);
}

int main(int argc, char *argv[])
{
   	int serv_sock;
	int clnt_sock;
	int str_len, i;
	int p_pid = getpid();
	char p_id[] = "2013136035";
	int c_pid;

	char message[BUF_SIZE];


	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;


	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(atoi(argv[1]));
	
	if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
		error_handling("bind() error"); 
	
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");
	
	clnt_addr_size=sizeof(clnt_addr);  


	clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr, &clnt_addr_size);
	if(clnt_sock==-1)
		error_handling("accept() error");
	else
		printf("Conneted client \n");

	write(clnt_sock,&p_pid,4);
	write(clnt_sock,p_id,strlen(p_id));  
         
	printf("producer : %s, %d\n", p_id,p_pid);
	sleep(5);

	read(clnt_sock,&c_pid,4);
 	str_len=read(clnt_sock,message,BUF_SIZE);
	
	message[str_len] = 0;
        printf("consumer : %s %d\n",message,c_pid);
	
	close(clnt_sock);
	
	close(serv_sock);
   return 0;
}
