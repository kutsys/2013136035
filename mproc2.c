#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
void test_funct(int count,int i){
    time_t timer;
    struct tm* t;
    timer =time(NULL);
    t = localtime(&timer);
    printf("  p_thread : %d  ",i);
    printf(" time : %dh %dm %ds  ",t->tm_hour,t->tm_min,t->tm_sec);
    printf("count : %d\n",count);
    sleep(2);

}


void* subproc(void* i){
   int count =0;
   int n = *(int *)i;
   while(count< 20){
       srand(time(NULL));
       int r= rand()%10;
       sleep(r);
       count++;
       test_funct(count,n);
    }   
}

int main()
{
    int i=0;
     int j=0;
    int taskID[10];
    int res=0;
    pthread_t p_thread[10];
    void *thread_result;
    int num = 20;
    while(i<10){
        taskID[i]=i;
        res = pthread_create(&p_thread[i], NULL,subproc,(void*)&taskID[i]);
	printf("thread create : %d\n",i);
        if(res !=0){
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        i++;
    }
	
    while(j<10){
	

       res =  pthread_join(p_thread[j], &thread_result);
       if(res !=0){
           perror("Thread join failed");
           exit(EXIT_FAILURE);
       }
	printf("thread join : %d\n",taskID[j]);
       j++;
    }
    printf("Finished (process)\n");
    return 0;
}

