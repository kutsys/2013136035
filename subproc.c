#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void test_funct(int count){
    time_t timer;
    struct tm* t;
    timer=time(NULL);
    t = localtime(&timer);
    printf("  PID : %d\n",getpid());
    printf(" time : %dh %dm %ds\n",t->tm_hour,t->tm_min,t->tm_sec);
    printf("count : %d\n",count);

}

int main(int argc, char *argv[]){
    int count = 0;
    while(count < atoi(argv[1])){
        srand(time(NULL));
        int r = rand()%10;
        sleep(r);
        count++;
        test_funct(count);
    }
    return 0;
}
