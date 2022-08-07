// #include <stdio.h>
// #include <stdlib.h>

// void printArr(int* arr, int len) {
//     for (int i = 0; i < len; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void merge(int* arr, int* temp, int l, int mid, int r) {
//     int l_pos = l;
//     int r_pos = mid + 1;
//     int pos = l;

//     while (l_pos <= mid && r_pos <= r) {
//         if (arr[l_pos] < arr[r_pos])
//             temp[pos++] = arr[l_pos++];
//         else
//             temp[pos++] = arr[r_pos++];
//     }

//     while (l_pos <= mid)
//         temp[pos++] = arr[l_pos++];
    
//     while(r_pos <= r)
//         temp[pos++] = arr[r_pos++];

//     while (l <= r) {
//         arr[l] = temp[l];
//         l++;
//     }
// }

// void partition(int* arr, int* temp, int l, int r) {
//     if (l < r) {
//         int mid = (l + r) / 2;
//         partition(arr, temp, l, mid);
//         partition(arr, temp, mid + 1, r);
//         merge(arr, temp, l, mid, r);
//     }
// }

// void mergeSort(int* arr, int size) {
//     int* temp = (int*)malloc(sizeof(int) * size);
//     partition(arr, temp, 0, size - 1);
//     free(temp);
// }

// int main() {
//     int arr[] = {10, 3, 5, 2, 8, 6, 12};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printArr(arr, len);

//     mergeSort(arr, len);

//     printArr(arr, len);

//     return 0;
// }
