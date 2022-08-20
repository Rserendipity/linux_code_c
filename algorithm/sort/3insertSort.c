// #include <stdio.h>

// void printArr(int* arr, int len) {
//     for (int i = 0; i < len; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void swap(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void insertSort(int* arr, int size) {
//     for (int i = 1; i < size; i++) {
//         for (int j = i; j >= 1 && arr[j] < arr[j - 1]; j--)
//             swap(&arr[j], &arr[j - 1]);
//     }
// }

// int main() {
//     int arr[] = {10, 3, 5, 2, 8, 6, 12};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printArr(arr, len);

//     insertSort(arr, len);

//     printArr(arr, len);

//     return 0;
// }
