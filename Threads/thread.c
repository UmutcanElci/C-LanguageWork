#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NTHREADS 10
void *countFunction(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main() {
  // Mutexes Block access to variables by other threads
  // Joins Make a thread wait till another thread finishes

  pthread_t thread_id[NTHREADS];
  int i, j;

  for (i = 0; i < NTHREADS; i++) {

    pthread_create(&thread_id[i], NULL, countFunction, NULL);
  }
  for (j = 0; j < NTHREADS; j++) {

    pthread_join(thread_id[j], NULL);
  }

  printf("Final counter value %d\n", counter);
}

void *countFunction(void *ptr) {
  printf("Thread number %ld\n", pthread_self());
  pthread_mutex_lock(&mutex1);
  counter++;
  pthread_mutex_unlock(&mutex1);
}
