#include <stdio.h>

int main()
{
    for (int i = 0; i < 10; i++) {
        // 执行10次，判断条件会被判断11次
        // 最后一次多一次判断才会跳出
    }
    printf("Hello world\n");
    return 0;
}

