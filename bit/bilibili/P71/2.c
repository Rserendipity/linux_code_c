// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     int a = 10;
//     int b = a--;  // 后至--，先使用，后自增

//     int c = 1;

//     // 未定义行为
//     // clang -> 9
//     // gcc -> 10
//     // msvc -> 12
//     int d = ++c + ++c + ++c;
//     printf("%d\n", d);

//     return 0;
// }