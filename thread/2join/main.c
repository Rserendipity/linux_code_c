#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int sum = 0;

// void *func(void *args) {
//     // 两个线程同时访问sum这个变量时会出现某些运算丢失的问题
//     // 这个时候就需要lock了,锁定共享的资源,防止同一资源被两个线程共用导致的运算丢失
//     for (int i = 0; i < MAX_SIZE; i++) {
//         sum += arr[i];
//     }
//     return NULL;
// }

// 添加锁，在同一时间内只让一个线程对全局变量进行修改
pthread_mutex_t lock;

void* func(void* args) {
    // 加锁
    pthread_mutex_lock(&lock);
    for (int i = 0; i < MAX_SIZE; i++) {
        sum += arr[i];
    }
    // 解锁
    pthread_mutex_unlock(&lock);
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
    pthread_mutex_init(&lock, NULL);

    pthread_create(&th1, NULL, func, NULL);
    pthread_create(&th2, NULL, func, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    // 加锁以后打印结果正常
    // 但是这样会有一个特别大的弊病，这样写的代码和单线程没有区别
    // 要避免这样的情况
    printf("sum = %d\n", sum);
    printf("realSum = %d\n", realSum * 2);

    return 0;
}