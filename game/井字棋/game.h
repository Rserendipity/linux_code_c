#define ROW 3
#define COL 3


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//游戏中有四种状态
//玩家赢   -    ‘*’
//电脑赢   -    ‘#’
//平局     -    ‘Q’
//继续     -    ‘C’
char IsWin(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);
