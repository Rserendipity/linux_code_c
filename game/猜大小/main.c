#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//函数声明
void test();
void again();
void menu();
void game();
int generate_num();


void menu()
{
	printf("\n");
	printf("****************************\n");
	printf("*****       猜数字      ****\n");
	printf("*****   请输入1或者0    ****\n");
	printf("*****  1.开始   0.退出  ****\n");
	printf("****************************\n");
	printf("\n");
}


void again()
{
	printf("\n");
	printf("想再玩一次吗？\n");
	printf("输入1再玩一次，输入0退出游戏:>");
}


int main()
{
	test();//调用test函数
	return 0;
}


void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);//根据用户的输入经行选择开始游戏还是退出
		switch (input)
		{
		case 1:
			game();//调用游戏函数
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);//同时可以使用用户输入的值来控制do—while循环
}


void game()
{
	int temp;
	int input;
	printf("请输入你想猜的数字的范围(左小右大，用空格隔开):>");
	temp = generate_num();//随机数生成函数，得到随机值
	do//进行do—while循环，直到用户输入正确的数停止
	{
		printf("请输入你猜的数:>");
		scanf("%d", &input);
		if (input == temp)
		{
			printf("猜对啦！\n");
			break;
		}
		else if (input < temp)
		{
			printf("小啦小啦！\n");
		}
		else if (input > temp)
		{
			printf("大啦大啦！\n");
		}
	} while (1);
	int a;
	do//询问是否再玩一次
	{
		again();
		scanf("%d", &a);
		switch (a)
		{ 
		case 1:
			game();//递归调用，重新开始游戏
		case 0:
			printf("退出游戏！\n");
			exit(0);//退出程序
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (a);//同时可以使用用户输入的值来控制do—while循环
}


int generate_num()
{
	int x, y, z;
	srand((unsigned int)time(NULL) * 100);//使用时间戳来生成随机数字，输入范围较小时*100可以去掉
	scanf("%d%d", &x, &y);//给定生成随机数的范围
	if (x > y)//判断是否符合要求
	{
		printf("你输入的前一个数字比后一个数字大哦！\n");
		printf("请重新输入:>");
		generate_num();
	}
	else if (x == y)
	{
		printf("你输入两个数字一样哦！\n");
		printf("请重新输入:>");
		generate_num();
	}
	else
	z = rand() % y + x;//生成随机数
	return z;
}
