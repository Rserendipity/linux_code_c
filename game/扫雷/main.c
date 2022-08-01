#include "game.h"

void menu() {
    printf("**********************\n");
    printf("**      1.play      **\n");
    printf("**      0.exit      **\n");
    printf("**********************\n");
}

int main() {
    int input = 0;
    int flag = 0;
    while (1) {
        menu();
        scanf("%d", &input);
        switch (input) {
        case 1:
            flag = Game();
            break;
        case 0:
            DelGame();
            printf("退出\n");
            return 0;
            break;
        default:
            printf("输入错误!\n");
            break;
        }
        if (flag == -1)
            printf("you lose\n");
        if (flag == 1)
            printf("you win\n");
    }

    return 0;
}