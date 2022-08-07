#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct MyArgs {
    //
    int first;
    int last;
    int sum;
} MyArgs;

int arr[MAX_SIZE];

void *func(void *args) {
    MyArgs *option = (MyArgs *)args;
    for (int i = option->first; i < option->last; i++) {
        option->sum += arr[i];
    }
}

int main() {
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 50;
    }

    MyArgs args1 = {0, MAX_SIZE / 2, 0};
    MyArgs args2 = {MAX_SIZE / 2, MAX_SIZE, 0};

    pthread_t th1;
    pthread_t th2;

    pthread_create(&th1, NULL, func, &args1);
    pthread_create(&th2, NULL, func, &args2);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("s1 = %d\n", args1.sum);
    printf("s2 = %d\n", args2.sum);
    printf("s = %d\n", args1.sum + args2.sum);

    return 0;
}