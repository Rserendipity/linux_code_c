#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a = 1;
    int b = a << 31;
    printf("%d\n", b);

    a = -1;
    // 使用的算术右移
    b = a >> 1; 
    printf("%d", b);
    return 0;
}