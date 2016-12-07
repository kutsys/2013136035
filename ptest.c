#include <stdio.h>
#include <unistd.h>
#include <time.h>
void getTime();
int main()
{
    getTime(); // 현재시간 호출...
    return 0;
}

void getTime(){
  time_t current_time;
  struct tm *t; // 알맞은 형식으로 변환해주는 구조체..

  while(1){
     sleep(2); // 2초마다 출력
     current_time= time(NULL);
     t = localtime(&current_time); // 로컬 시간 저장..
     printf("%dh %dm %ds \n",t->tm_hour,t->tm_min,t->tm_sec);
     // 시, 분, 초 단위로 변환해서 출력
  }
}
