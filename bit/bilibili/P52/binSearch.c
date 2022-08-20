#include <stdio.h>

int binSearch(int* arr, int size, int n) {
    int l = 0; 
    int r = size - 1;
    int mid = 0; 
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == n) {
            return mid;
        } else if (arr[mid] > n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("index = %d\n", binSearch(arr, size, 3));
    return 0;
}

