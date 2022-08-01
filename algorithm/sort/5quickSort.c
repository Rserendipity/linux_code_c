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

// int partition(int* arr, int l, int r) {
//     int temp = arr[l];

//     while (l < r) {
//         while (l < r && arr[r] >= temp)
//             r--;
//         if (l < r) {
//             arr[l] = arr[r];
//             l++;
//         }
//         while (l < r && arr[l] < temp)
//             l++;
//         if (l < r) {
//             arr[r] = arr[l];
//             r--;
//         }
//     }
//     arr[l] = temp;
//     return l;
// }

// void quickSort(int* arr, int head, int tail) {
//     if (head < tail) {
//         int mid = partition(arr, head, tail);
//         quickSort(arr, head, mid - 1);
//         quickSort(arr, mid + 1, tail);
//     }
// }

// int main() {
//     int arr[] = {10, 3, 5, 2, 8, 6, 12};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printArr(arr, len);

//     quickSort(arr, 0, len - 1);

//     printArr(arr, len);

//     return 0;
// }
