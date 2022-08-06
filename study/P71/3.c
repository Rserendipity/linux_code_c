#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1() {
    int i, a = 0, b = 2, c = 3, d = 4;
    // 计算到a++ 时就会停止，a先使用，所以表达式直接为0，不会进行后面的运算
    i = a++ && ++b && d++;
    printf("i = %d\na = %d \nb = %d \nc = %d \nd = %d\n", i, a, b, c, d);
}

void test2() {
    int i, a = 0, b = 2, c = 3, d = 4;
    // 计算到++b的时候会停止，表达式已经为真，不会继续下去
    i = a++ || ++b || d++;
    printf("i = %d\na = %d \nb = %d \nc = %d \nd = %d", i, a, b, c, d);
}

int main() {
    test1();
    test2();

    return 0;
}