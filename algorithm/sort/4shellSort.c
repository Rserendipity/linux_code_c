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

// void shellSort(int* arr, int size) {
//     int i, j, inc;
//     for (inc = size / 2; inc > 0; inc /= 2) {
//         for (i = inc; i < size; i++) {
//             for (j = i; j >= inc && arr[j] < arr[j - inc]; j-=inc) {
//                 swap(&arr[j], &arr[j - inc]);
//             }
//         }
//     }
// }

// int main() {
//     int arr[] = {10, 3, 5, 2, 8, 6, 12};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printArr(arr, len);

//     shellSort(arr, len);

//     printArr(arr, len);

//     return 0;
// }
