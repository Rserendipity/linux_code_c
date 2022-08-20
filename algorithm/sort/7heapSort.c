// #include <stdio.h>
// #include <stdlib.h>

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

// void heapify(int* arr, int size, int pos) {
//     int max = pos;
//     int lch = pos * 2 + 1;
//     int rch = pos * 2 + 2;

//     if (lch < size && arr[lch] > arr[max])
//         max = lch;
//     if (rch < size && arr[rch] > arr[max])
//         max = rch;
    
//     if (max != pos) {
//         swap(&arr[max], &arr[pos]);
//         heapify(arr, size, max);
//     }
// }

// void heapSort(int* arr, int size) {
//     for (int i = (size - 1) / 2; i >= 0; i--) {
//         heapify(arr, size, i);
//     }

//     for (int i = size - 1; i >= 0; i--) {
//         swap(&arr[i], &arr[0]);
//         heapify(arr, i, 0);
//     }
// }

// int main() {
//     int arr[] = {10, 3, 5, 2, 8, 6, 12};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printArr(arr, len);

//     heapSort(arr, len);

//     printArr(arr, len);

//     return 0;
// }
