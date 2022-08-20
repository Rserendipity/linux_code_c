#include <stdio.h>

int main()
{
    double result = 0;
    int flag = 1;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 1) {
            flag = 1;
        } else {
            flag = -1;
        }
        result += flag * (1/(double)i);
    }
    printf("%lf\n", result);

    return 0;
}

