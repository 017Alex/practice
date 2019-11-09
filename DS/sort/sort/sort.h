#pragma once
#include"common.h"

void PrintArray(int* ar, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}

void TwoWayInsertSort(int* ar, int left, int right)
{
	int size = right - left + 1;
	int* tmp = (int*)malloc(sizeof(int) * n);
	
	free(tmp);
	tmp = NULL;
}