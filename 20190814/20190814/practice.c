//1.完成猜数字游戏。
//
//2.写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）
//
//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。
//
//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//void menu()
//{
//	printf("*********************************\n");
//	printf("***********1.开始游戏************\n");
//	printf("***********0. 退出 **************\n");
//	printf("*********************************\n");
//}
//
//
//void game()
//{
//	int num = rand() % 100 + 1;
//	int n = 0;
//	while (1)
//	{
//		printf("请输入数字：");
//		scanf("%d", &n);
//		if (n > num)
//		{
//			printf("猜大了\n");
//		}
//		else if (n < num)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("猜对了！\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int n = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("请输入：");
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("请输入正确的数字！\n");
//			break;
//		}
//	} while (n);
//	return 0;
//}
//
//
//
//
//
//
//
//
//int Search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[1]);
//	int ret = Search(arr, 8, sz);
//	if (-1 == ret)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是%d\n", ret);
//	}
//	return 0;
//}
//
//
//
//
//
//int main()
//{
//	char password[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误，请重新输入！\n");
//		}
//		if (i == 3)
//		{
//			printf("三次错误，退出程序！\n");
//		}
//	}
//	return 0;
//}






int main()
{
	char n;
	while (1)
	{
		scanf("%c", &n);
		if (n >= 'a' && n <= 'z')
		{
			printf("%c", n - 32);
		}
		else if (n >= 'A' && n <= 'Z')
		{
			printf("%c", n + 32);
		}
	}
	return 0;
}