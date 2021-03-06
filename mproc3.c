#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

pthread_mutex_t  mutex;
void test_funct(int m_count,int m_n){
    time_t ltime;
    struct tm *ts;
    ltime = time(NULL);
    ts = localtime(&ltime);
    printf("  ID: %d   COUNT : %d  ",m_n,m_count);

    printf("Time: %d-%d-%d %d:%d:%d\n",ts->tm_year+1900,ts->tm_mon+1,ts->tm_mday,ts->tm_hour,ts->tm_min,ts->tm_sec);
    sleep(2);

}


void* subproc(void* id){
   int count = 0;
   int  n = *(int*)id;
   while(count< 20){
       
       int r= rand()%10;
       sleep(r);
       pthread_mutex_lock(&mutex);
       count++;
       test_funct(count,n);
       pthread_mutex_unlock(&mutex);
    }   
}

int main()
{
    int i=0;
    int j=0;
    int res=0;
    int taskID[10];
    pthread_mutex_init(&mutex, NULL);
    pthread_t p_thread[10];
    void *thread_result;
    srand(time(NULL));
    printf("2013136035 Hyeon Ji Ra\n");
    while(i<10){
        taskID[i] =i;
        res = pthread_create(&p_thread[i], NULL,subproc,(void*)&taskID[i]);
        if(res !=0){
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        i++;
    }

    while(j<10){
       res =  pthread_join(p_thread[j], &thread_result);
       if(res !=0){
           perror("Thread creation failed");
           exit(EXIT_FAILURE);
       }
       j++;
    }
    pthread_mutex_destroy(&mutex);
    printf("Finished Successfully\n");
    return 0;
}
