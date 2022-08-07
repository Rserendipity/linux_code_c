#include <stdio.h>
#include <math.h>

int isPrimer(int num) {
    for (int i = 2; i < sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    for (int i = 100; i <= 200; i++) {
        if (isPrimer(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

