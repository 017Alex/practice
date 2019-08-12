#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>


//1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
//
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 5,4,3,2,1 };
//	int i;
//	int tem;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 5; i++)
//	{
//		tem = arr2[i];
//		arr2[i] = arr1[i];
//		arr1[i] = tem;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int i;
//	float sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += pow(-1, i + 1) * 1 / i;
//	}
//	printf("%f", sum);
//	return 0;
//}


int main()
{
	int i;
	int flag = 0;
	for (i = 1; i <= 100; i++)
	{
		if (9 == i % 10)
		{
			flag++;
		}
		if (9 == i / 10)
		{
			flag++;
		}
	}
	printf("%d\n", flag);
	return 0;
}