#define _CRT_SECURE_NO_WARNINGS 1
#include "saolei.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
}

void menu()
{
	printf("**************************************\n");
	printf("********        1.play        ********\n");
	printf("********        0.exit        ********\n");
	printf("**************************************\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1: 
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误！请重新输入：");
			break;
		}
	} while (input);
	return 0;
}