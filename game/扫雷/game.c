#include <malloc.h>
#include "game.h"

static Map *map = NULL;

int boomSize(int x, int y);

Map *gameInit() {
    // 开辟空间
    map = (Map *) malloc(sizeof(Map));
    map->u_map = (UsrMap *) malloc(sizeof(UsrMap));
    map->c_map = (Caculate *) malloc(sizeof(Caculate));
    map->u_map->sum = 0;
    
    // 计算数组赋初值
    for (int i = 0; i < ROW + 2; i++) {
        for (int j = 0; j < COL + 2; j++) {
            map->c_map->arr[i][j] = 0;
        }
    }
    
    // 用户数组赋初值
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            map->u_map->arr[i][j] = -1;
        }
    }
    
    // 放雷
    for (int i = 0; i < BOOMSIZE; i++) {
        int flag = 1;
        while (flag) {
            // 生成1～9的数字
            int x = rand() % 9 + 1;
            int y = rand() % 9 + 1;
            // 成功放下雷，把标志位改成0，停止循环
            if (map->c_map->arr[x][y] == 0) {
                map->c_map->arr[x][y] = 1;
                flag = 0;
            }
        }
    }
    
    int temp[ROW][COL] = {0};
    
    for (int i = 0; i < COL;i++) {
        for (int j = 0; j < ROW;j++) {
            temp[i][j] = -1;
        }
    }
    
    for (int i = 1; i < COL+1;i++) {
        for (int j = 1; j < ROW+1;j++) {
            temp[i - 1][j - 1] = boomSize(i, j);
        }
    }
    
    for (int i = 0; i < COL;i++) {
        for (int j = 0; j < ROW;j++) {
            map->u_map->sum += temp[i][j];
        }
    }
}

int boomSize(int x, int y) {
    return map->c_map->arr[x - 1][y - 1] +
           map->c_map->arr[x - 1][y] +
           map->c_map->arr[x - 1][y + 1] +
           map->c_map->arr[x][y - 1] +
           map->c_map->arr[x][y + 1] +
           map->c_map->arr[x + 1][y - 1] +
           map->c_map->arr[x + 1][y] +
           map->c_map->arr[x + 1][y + 1];
}

int isBoom(int x, int y) {
    return map->c_map->arr[x][y];
}

int winOrDefault() {
    int sum = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            sum += map->u_map->arr[i][j];
    }
    if (sum == map->u_map->sum - BOOMSIZE)
        return 1;
    
    int x;
    int y;
    scanf("%d%d", &x, &y);
    
    if (isBoom(x, y))
        return -1;
    else {
        map->u_map->arr[x - 1][y - 1] = boomSize(x, y);
        return 0;
    }
}

void reflesh() {
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++){
            if (map->u_map->arr[i][j] == -1)
                printf("* ");
            else
                printf("%d ", map->u_map->arr[i][j]);
        }
        printf("\n");
    }
}

void DelGame() {
    free(map->c_map);
    free(map->u_map);
    free(map);
}

int Game() {
    // 检查全局变量，如果有值了（即调用过game函数）
    // 先进行释放，再进行初始化，避免内存泄漏
    if (map != NULL)
        // 销毁当前map指向的空间
        DelGame();
    
    // 标志位
    // flag == 1  赢了
    // flag == 0  扫雷没有完成
    // flag == -1 输了
    int flag = 0;
    
    // 分配内存空间并赋初值
    gameInit();
    
    // 循环，在这个函数里进行输入，判断输赢等，函数会返回标志位的值
    while (1) {
        // 判断输赢
        flag = winOrDefault();
        if (flag == 1 || flag == -1)
            return flag;
        // 刷新显示
        reflesh();

    }
}