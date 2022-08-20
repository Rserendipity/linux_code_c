// #include <stdio.h>

// void hanoi(int n, char A, char B, char C) {
//     if (n == 1) {
//         // 递归出口，当 n == 1时，只需要把A（起始柱）柱上的移动到C（目标柱）柱上
//         printf("%c -> %c\n", A, C);
//     } else {
//         // 否则进行递归调用
//         // 把A（起始柱）上的 n-1 个盘移动到B（临时柱）上，再把A（起始柱）移动到C（目标柱）上
//         hanoi(n - 1, A, C, B);
//         // A移动到C
//         printf("%c -> %c\n", A, C);
//         // 递归的把B（临时柱）柱上的移动到C上即可 
//         hanoi(n - 1, B, A, C);
//     }
// }

// int main() {
//     hanoi(3, 'A', 'B', 'C');
//     return 0;
// }