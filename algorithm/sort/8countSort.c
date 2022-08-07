// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void printArr(int* arr, int len) {
//     for (int i = 0; i < len; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void countSort(int* arr, int size) {
//     int max = arr[0];
//     for (int i = 0; i < size; i++) {
//         if (arr[i] > max)
//             max = arr[i];
//     }

//     int* count = (int*)malloc(sizeof(int) * (max + 1));
//     memset(count, 0, sizeof(int) * (max + 1));

//     for (int i = 0; i < size; i++) {
//         count[arr[i]] += 1;
//     }

//     for (int i = 1; i < max + 1; i++) {
//         count[i] += count[i - 1];
//     }

//     int* temp = (int*)malloc(sizeof(int) * size);

//     for (int i = 0; i < size; i++) {
//         temp[count[arr[i]] - 1] = arr[i];
//         count[arr[i]] -= 1;
//     }

//     for (int i = 0; i < size; i++) {
//         arr[i] = temp[i];
//     }

//     free(temp);
//     free(count);
// }
// int main() {
//     int arr[] = {10, 3, 5, 2, 8, 6, 12};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printArr(arr, len);

//     countSort(arr, len);

//     printArr(arr, len);

//     return 0;
// }
