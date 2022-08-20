// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     // 三行，四列，但实际上就是顺序存储的
//     // 也就是连续的12个int空间
//     // int arr[3][4] = {0};
    
//     /* 
//     1 2 0 0 
//     3 4 0 0
//     5 6 0 0
//     */
//     int arr[3][4] = {{1,2}, {3,4}, {5,6}};
    
//     int* p = &arr[0][0];

//     for (int i = 0; i < 12; i++) {
//         printf("%d ", p[i]);
//     }  

//     return 0;
// }