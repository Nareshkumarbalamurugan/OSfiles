#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by each thread
void *threadFunction(void *arg) {
    int threadNum = *(int *)arg;
    printf("Thread %d is running...\n", threadNum);
    sleep(1); // Simulating work
    printf("Thread %d has finished execution.\n", threadNum);
    pthread_exit(NULL);
}

int main() {
    int numThreads = 3;
    pthread_t threads[numThreads];
    int threadArgs[numThreads];

    // Creating multiple threads
    for (int i = 0; i < numThreads; i++) {
        threadArgs[i] = i + 1;
        if (pthread_create(&threads[i], NULL, threadFunction, &threadArgs[i]) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Waiting for all threads to complete
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed execution.\n");
    return 0;
}
