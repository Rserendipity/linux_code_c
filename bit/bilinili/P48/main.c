#include <stdio.h>

void print(int a) {
    if (a < 10) {
        printf("%d ", a);
    } else {
        printf("%d ", a % 10);
        print(a / 10);
    }
}

int main() {
    int a = 12345;
    print(a);
    return 0;
}