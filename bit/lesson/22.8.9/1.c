#include <stdio.h>

int main() {
    // 低位放的低字节，高位放高字节，就是小端存储
    //数字的   高位     低位
    //      0x 11 22 33 44
    //
    //  44    33    22    11
    //
    // 低地址    --->    高地址

    int a = 1;
    // 内存
    // 低  ->  高
    // 01 00 00 00
    // ^ a的空间
    char* pch = (char*)&a;
    // 01 00 00 00
    // ^ 让pch指向这里
    // 如果pch的值是1
    // 那么就为小端存储，即数值的低位，存在了内存的低位
    printf("%d", *pch);

    return 0;
}
