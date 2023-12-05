#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4 // num of threads being used
#define DARTS_PER_THREAD 250

pthread_mutex_t lock;
int darts_inside_circle = 0;

void* throwDarts(void* arg) {
    unsigned int seed = rand();
    int darts_inside = 0;

    for (int i = 0; i < DARTS_PER_THREAD; i++) {
        double x = (double)rand_r(&seed) / RAND_MAX * 2; // Random x-coordinate
        double y = (double)rand_r(&seed) / RAND_MAX * 2; // Random y-coordinate

        if (((x - 1) * (x - 1) + (y - 1) * (y - 1)) <= 1) {
            darts_inside++;
        }
    }

    pthread_mutex_lock(&lock);
    darts_inside_circle += darts_inside;
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, throwDarts, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    double estimated_pi = 4.0 * darts_inside_circle / (NUM_THREADS * DARTS_PER_THREAD);
    printf("Estimated Pi: %f\n", estimated_pi);

    pthread_mutex_destroy(&lock);
    return 0;
}
