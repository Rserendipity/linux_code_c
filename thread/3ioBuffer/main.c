#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int sum[1001] = {0};

void* func(void* args) {
    int* p = args;
    for (int i = 0; i < MAX_SIZE; i++) {
        sum[*p] += arr[i];
    }
}

int main() {
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 5;
    }

    int realSum = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        realSum += arr[i];
    }

    pthread_t th1;
    pthread_t th2;

    int args1 = 0;
    int args2 = 1000;

    pthread_create(&th1, NULL, func, &args1);
    pthread_create(&th2, NULL, func, &args2);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("sum = %d\n", sum[0] + sum[1000]);
    printf("realSum = %d\n", realSum * 2);
    return 0;
}
