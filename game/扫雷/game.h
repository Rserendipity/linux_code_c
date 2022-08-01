#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COL 4
#define ROW 4
#define BOOMSIZE 3

typedef struct UsrMap {
    int arr[COL][ROW];
    int sum;
} UsrMap;

typedef struct Caculate {
    int arr[COL+2][ROW+2];
} Caculate;

typedef struct Map{
    UsrMap* u_map;
    Caculate* c_map;
} Map;

int Game();
void DelGame();
