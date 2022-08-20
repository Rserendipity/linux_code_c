#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverStr(char* s, int head, int tail) {
    if (head < tail) {
        swap(&s[head], &s[tail]);
    } else {
        reverStr(s, head + 1, tail - 1);
    }
}

int main() {
    char arr[] = "abcdef";
    int size = strlen(arr);

    printf("%s\n", arr);

    reverStr(arr, 0, size - 1);

    printf("%s\n", arr);

    return 0;
}