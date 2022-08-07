#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int getMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int getRadix(int num) {
    int n = 1;
    while (num /= 10)
        n++;
    return n;
}

void radixSort(int* arr, int size) {
    int* temp = (int*)malloc(sizeof(int) * size);
    int* count = (int*)malloc(sizeof(int) * 10);
    memset(count, 0, sizeof(int) * 10);

    int max = getMax(arr, size);
    int n = getRadix(max);

    for (int j = 0; j < n; j++) {
        int div = (int)pow(10, j);
        for (int i = 0; i < size; i++) {
            count[arr[i] / div % 10] += 1;
        }

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--) {
            temp[count[arr[i] / div % 10] - 1] = arr[i];
            count[arr[i] / div % 10] -= 1;
        }

        for (int i = 0; i < size; i++) {
            arr[i] = temp[i];
        }

        memset(count, 0, sizeof(int) * 10);
    }

    free(temp);
    free(count);
}

int main() {
    int arr[] = {10, 3, 5, 2, 8, 6, 12};
    int len = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, len);

    radixSort(arr, len);

    printArr(arr, len);

    return 0;
}
