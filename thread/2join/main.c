<<<<<<< HEAD
#include <stdio.h>

int main() {
    
=======
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int sum = 0;

void *func(void *args) {
    // 两个线程同时访问sum这个变量时会出现某些运算丢失的问题
    // 这个时候就需要lock了,锁定共享的资源,防止同一资源被两个线程共用导致的运算丢失
    for (int i = 0; i < MAX_SIZE; i++) {
        sum += arr[i];
    }
    return NULL;
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

    pthread_create(&th1, NULL, func, NULL);
    pthread_create(&th2, NULL, func, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("sum = %d\n", sum);
    printf("realSum = %d\n", realSum * 2);

>>>>>>> master
    return 0;
}