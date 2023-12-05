//WARNING: THIS CODE HAS A BUG!
// psum4.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "csapp.h"
#include <semaphore.h>
#define N 1000000

int threads; // global variable is shared
double a[N]; // global variable is shared
double sum=0; // global variable is shared
sem_t mutex; // semaphore protect

void* thread_sum(void* rank);

int main(int argc, char* argv[]) {
  clock_t start,end;
  double elapsed;

  Sem_init(&mutex, 0, 1);

  if (argc != 2) {
    printf("Usage: %s number-of-threads\n", argv[0]);
    exit(0);
  }

  printf("hi (main thread)\n");

  threads = atoi(argv[1]);
  pthread_t* thread_handles = malloc(threads * sizeof(pthread_t));

  // fill array with 1s, don't time this initialization
  for (int i=0; i<N; ++i) {
    a[i]=1;
  }

  start = clock();
  for (int thread=0; thread < threads; thread++) {
    pthread_create(&thread_handles[thread], NULL, thread_sum, (void*)(long)thread);
  }

  int chunk_size = N / threads;
  for (int thread = 0; thread < threads; thread++) {
    int start_index = thread * chunk_size;
    int end_index = start_index + chunk_size;
    double local_sum = 0;

    for (int i = start_index; i < end_index; i++) {
      local_sum += a[i];
    }

    P(&mutex);
    sum += local_sum;
    V(&mutex);
  }

  for (int thread=0; thread<threads; thread++) {
    pthread_join(thread_handles[thread], NULL);
  }
  free(thread_handles);

  end = clock();
  elapsed = ((double) (end-start)) / CLOCKS_PER_SEC;
  printf("elapsed=%f\n",elapsed);

  printf("bye (main thread)\n");
  printf("sum=%f (N=%d)\n",sum,N);
  return 0;
}

void* thread_sum(void* rank) {
  long my_rank = (long)rank;
  int chunk_size = N / threads;
  int start_index = my_rank * chunk_size;
  int end_index = start_index + chunk_size;
  double local_sum = 0;

  for (int i = start_index; i < end_index; i++) {
    local_sum += a[i];
  }

  P(&mutex);
  sum += local_sum;
  V(&mutex);
  return NULL;
}
