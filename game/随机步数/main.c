#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 10
#define LOW 10
int is_full(int* arr) {
	return (arr[0] + arr[1] + arr[2] + arr[3]) == 0;
}
void setArr(int* arr) {
	for (int i = 0; i < 4; i++)
		arr[i] = 0;
}
int main()
{
	char arr[COL+2][LOW+2] = { 0 };
	srand((unsigned int)time(NULL));
	char step = 'a';
	int row = 1;
	int low = 1;

	int flag[4] = { 0 };

	for (int i = 1; i < COL+1; i++) {
		for (int j = 1; j < LOW+1; j++) {
			arr[i][j] = '*';
		}
	}
	for (int i = 0; i < COL+2; i++) {
		arr[0][i] = '&';
		arr[COL+1][i] = '&';
		arr[i][0] = '&';
		arr[i][LOW+1] = '&';
	}
	arr[row][low] = step++;
	while (1) {
		//printf("%d", 12123123);
		if (step == 'z' + 1)
			step = 'A';
		if (arr[row-1][low] == '*')
			flag[0] = 1;
		if (arr[row][low+1] == '*')
			flag[1] = 1;
		if (arr[row+1][low] == '*')
			flag[2] = 1;
		if (arr[row][low-1] == '*')
			flag[3] = 1;
		if (is_full(flag))
			break;
		while (1){
			int temp = rand() % 4;
			if (flag[temp] == 1) {
				if (temp == 0) {
					arr[--row][low] = step++;
				}
				if (temp == 1) {
					arr[row][++low] = step++;
				}
				if (temp == 2) {
					arr[++row][low] = step++;
				}
				if (temp == 3) {
					arr[row][--low] = step++;
				}
				break;
			}
		}

		setArr(flag);
	}
	for (int i = 1; i < COL+1; i++) {
		for (int j = 1; j < LOW+1; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}