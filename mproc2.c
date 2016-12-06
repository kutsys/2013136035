#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
void test_funct(int count){
    time_t timer;
    struct tm* t;
    timer =time(NULL);
    t = localtime(&timer);
    printf("  PID : %d\n",getpid());
    printf(" time : %dh %dm %ds\n",t->tm_hour,t->tm_min,t->tm_sec);
    printf("count : %d\n",count);

}


void* subproc(void* num){
   int count =0;
   while(count< *(int*)num){
       srand(time(NULL));
       int r= rand()%10;
       sleep(r);
       count++;
       test_funct(count);
    }   
}

int main()
{
    int i=0;
    int res=0;
    pthread_t p_thread[10];
    void *thread_result;
    int num = 20;
    while(i<10){
        res = pthread_create(&p_thread[i], NULL,subproc,(void*)&num);
        if(res !=0){
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        i++;
    }
    i = 0;
    while(i<10){
       res =  pthread_join(p_thread[i], &thread_result);
       if(res !=0){
           perror("Thread creation failed");
           exit(EXIT_FAILURE);
       }
       i++;
    }
    printf("Finished (process)\n");
    return 0;
}

