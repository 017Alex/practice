#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)//初始化棋盘
{
	memset(board, ' ', row * col * sizeof(board[0][0]));
}

void DisplayBoard(char board[ROW][COL], int row, int col)//打印棋盘
{
	//   |   |   
	//---|---|---
	//   |   |   
	//---|---|---
	//   |   |   
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:\n");
	while (1)
	{
		printf("请输入坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入!\n");
			}
		}
		else
		{
			printf("坐标有误！\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static int IsFull(char board[ROW][COL], int row, int col)//判断棋盘是否下满
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)//判断输赢
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if ((board[i][j - 1] == board[i][j]) && (board[i][j] == board[i][j + 1]) && board[i][j] != ' ')//行
			{
				return board[i][j];
			}
		}
	}
	for (j = 0; j < col; j++)
	{
		for (i = 1; i < row - 1; i++)
		{
			if ((board[i - 1][j] == board[i + 1][j]) && (board[i][j] == board[i + 1][j]) && board[i][j] != ' ')//列
			{
				return board[i][j];
			}
		}

	}
	for (i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if ((board[i - 1][i - 1] == board[i][i]) && (board[i][i] == board[i + 1][i + 1]) && board[i][j] != ' ')//对角线
			{
				return board[i][j];

			}
		}
	}
	for (i = row - 1; i > 0; i--)
	{
		for (j = 1; j < col - 1; j++)
		{
			if ((board[i + 1][j - 1] == board[i][j]) && (board[i][j] == board[i - 1][j + 1]) && board[i][j] != ' ')//对角线
			{
				return board[i][j];
			}
		}
	}
	if (IsFull(board, row, col) == 1)
	{
		return 'Q';//平局
	}
	return 'C';//继续游戏
}