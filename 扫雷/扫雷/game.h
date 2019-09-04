#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS (ROW+2)
#define COLS (COL+2)

#define DEFAULT_COUNT 80//À×Êý

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//³õÊ¼»¯
void DispalyBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);