#include "_cgo_export.h"
#include <stdio.h>
#include <pthread.h>

void DoIt() {
    printf("Hi from thread\n");
    for (int i = 0; i < 1000000; i++) {
        CallIt();
    }
}

void DoTest() {
  printf("Hi from DoTest\n");

  /* this variable is our reference to the second thread */
  pthread_t inc_x_thread;

  /* create a second thread which executes inc_x(&x) */
  if(pthread_create(&inc_x_thread, NULL, DoIt, NULL)) {

    fprintf(stderr, "Error creating thread\n");
    return;
  }

  pthread_join(inc_x_thread, NULL);
}
