#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//
//2.
////杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9



//void Move(int arr[], int sz)
//{
//	int* left = arr;
//	int* right = arr + sz - 1;
//	int tmp = 0;
//	while (left < right)
//	{
//		while ((left < right) && ((*left) % 2 != 0))
//		{
//			left++;
//		}
//		while ((left < right) && ((*right) % 2 == 0))
//		{
//			right--;
//		}
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Move(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




int Search(int arr[][3], int row, int col, int key)
{
	int i = 0;
	int j = col - 1;
	while ((j >= 0) && (i <= 2))
	{
		if (arr[i][j] == key)
			return 1;
		else if (arr[i][j] < key)
			i++;
		else
			j--;
	}
	return 0;
}

int main()
{
	int arr[][3] = { 1,2,3,4,5,6,7,8,9 };
	int row = 3;
	int col = 3;
	int key = 0;
	int ret = 0;
	scanf("%d", &key);
	ret = Search(arr, row, col, key);
	if (ret)
		printf("找到了\n");
	else
		printf("没找到\n");
	return 0;
}