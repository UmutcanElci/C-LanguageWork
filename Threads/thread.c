#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *workerThread(void * tid){
  long * myID = (long *) tid;

  printf("Hello This is Thread %ld\n",*myID);
} 

int main() {

  pthread_t tid0;
  pthread_create(&tid0, NULL, workerThread, (void *)&tid0);

  pthread_exit(NULL);

  return 0;
}

