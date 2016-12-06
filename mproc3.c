#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int count =0;
pthread_mutex_t  mutex;
void test_funct(int m_count){
    printf("  COUNT : %d\n",m_count);
    printf("2013136035 Hyeon Ji Ra\n");

}


void* subproc(void* num){
   
   while(count< *(int*)num){
       srand(time(NULL));
       int r= rand()%10;
       sleep(r);
       pthread_mutex_lock(&mutex);
       count++;
       test_funct(count);
       pthread_mutex_unlock(&mutex);
    }   
}

int main()
{
    int i=0;
    int res=0;
    pthread_mutex_init(&mutex, NULL);
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
    pthread_mutex_destroy(&mutex);
    printf("Finished Successfully\n");
    return 0;
}

