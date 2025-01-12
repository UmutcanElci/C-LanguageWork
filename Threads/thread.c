#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *countFunction();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main() {
  // Mutexes Block access to variables by other threads
  // Joins Make a thread wait till another thread finishes

  int rc1, rc2;
  pthread_t thread1, thread2;

  if ((rc1 = pthread_create(&thread1, NULL, &countFunction, NULL))) {

    printf("Thread creation falied %d\n", rc1);
  }
  if ((rc2 = pthread_create(&thread2, NULL, &countFunction, NULL))) {

    printf("Thread creation falied %d\n", rc2);
  }

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  exit(0);
}

void *countFunction() {
  pthread_mutex_lock(&mutex1);
  counter++;
  printf("Counter value: %d\n", counter);
  pthread_mutex_unlock(&mutex1);
}
