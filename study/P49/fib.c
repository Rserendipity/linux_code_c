#include <stdio.h>

int fib(int num) {
    if (num == 1 || num == 2)
        return 1;
    else
        return fib(num - 1) + fib(num - 2);
}

int main() {
    int num = fib(9);

    printf("%d\n", num);

    return 0;
}