// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     short a = 5;
//     int b = 10;
//     // sizeof的是在编译期间就算好了，所以不会进行赋值
//     // 并且以左边的结果为主，a已经开辟了空间，所以是把结果装到a里，不会进行整形提升，计算的字节数就是short的
//     printf("%d\n", sizeof(a = b + 2));
//     printf("%d\n", a);

//     return 0;
// }