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

// void selectSort(int* arr, int size) {
//     for (int i = 0; i < size; i++) {
//         int min = i;
//         for (int j = size - 1; j >= i; j--) {
//             if (arr[j] < arr[min])
//                 min = j;
//         }
//         swap(&arr[i], &arr[min]);
//     }
// }

// int main() {
//     int arr[] = {10, 3, 5, 2, 8, 6, 12};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printArr(arr, len);

//     selectSort(arr, len);

//     printArr(arr, len);

//     return 0;
// }
