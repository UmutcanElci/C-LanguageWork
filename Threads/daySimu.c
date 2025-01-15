#include <stdio.h>
#include <pthread.h>
#include <windows.h>

#define YEAR 365
#define DAY 24
#define HOUR 60
#define MINUTE 60

void *daySimulation(void *arg); 
int year = 0;
int day = 0;
int hour = 0;
int minute = 0;
int main(){
  pthread_t thread;


  pthread_create(&thread, NULL, &daySimulation, NULL);

  pthread_join(thread, NULL);

  return 0;

}

void *daySimulation(void *arg){
  for(;;){
    Sleep(1000);
    minute++;
    if(minute == MINUTE) {
      minute = 0;
      hour++;
    }
    if(hour == HOUR) {
      hour = 0;
      day++;
    }
    if(day == DAY) {
      day = 0;
      year++;
    }

    Sleep(1000);
    printf("Year: %d, Day: %d, Hour: %d, Minute: %d\n", year, day, hour, minute);

  }
}
