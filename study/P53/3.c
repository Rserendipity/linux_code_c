#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_pow(int num, int k) {
    if (k == 0) {
        return 1;
    } else {
        return num * my_pow(num, k - 1);
    }
}

int main() {
    int a = 2;
    printf("%d\n", my_pow(a, 4));
    return 0;
}