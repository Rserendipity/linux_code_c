#include <stdio.h>

int main()
{
    int i,j;
    for (i = 1, j = 1; i <= 100; i++) {
        if (j >= 20) 
            break;
        if (j % 3 == 1) {
            j += 3;
            continue;
        }
        j -= 5;
    }
    printf("%d\n", i);
    return 0;
}

