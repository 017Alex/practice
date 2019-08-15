#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>

//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//
//2.使用函数实现两个数的交换。
//
//3.实现一个函数判断year是不是润年。
//
//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//
//5.实现一个函数，判断一个数是不是素数。




//int List(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %-2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	List(line);
//	return 0;
//}
//
//
//
//int Swap(int * i, int * j)
//{
//	int flag;
//	flag = *j;
//	*j = *i;
//	*i = flag;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	Swap(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}
//
//
//
//
//
//int Leapyear(int n)
//{
//	if (n / 100 != 0 && n % 4 == 0)
//	{
//		return 1;
//	}
//	else if (n / 100 == 0 && n % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int year = 0;
//	int ret = 0;
//	scanf("%d", &year);
//	ret = Leapyear(year);
//	if (1 == ret)
//	{
//		printf("是闰年\n");
//	}
//	else if (0 == ret)
//	{
//		printf("不是闰年\n");
//	}
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
//int init(int *arr)
//{
//	int i = 0;
//	printf("请初始化数组：\n");
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	printf("数组已初始化为：\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int empty(int* arr)
//{
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		arr[i] = 0;
//	}
//	printf("数组已清空为：\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int reverse(int* arr)
//{
//	int temp = 0;
//	int i = 0;
//	for (i = 0; i < 2; i++)
//	{
//		temp = arr[i];
//		arr[i] = arr[4 - i];
//		arr[4 - i] = temp;
//	}
//	printf("逆置数组\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void menu()
//{
//	printf("************************************\n");
//	printf("***********1. 初始化数组 ***********\n");
//	printf("***********2.  清空数组  ***********\n");
//	printf("***********3.数组元素逆置***********\n");
//	printf("***********0.   退出     ***********\n");
//	printf("************************************\n");
//}
//
//int main()
//{
//	int arr[5] = {0};
//	int n;
//	do{
//		menu();
//		printf("请输入：\n");
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			init(arr);
//			break;
//		case 2:
//			empty(arr);
//			break;
//		case 3:
//			reverse(arr);
//			break;
//		case 0:
//			break;
//		default:
//			printf("输入错误，请重新输入！\n");
//			break;
//		}
//	} while (n);
//	return 0;
//}






int Prime(int n)
{
	int i = 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (0 == n % i)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int num = 0;
	int ret = 0;
	scanf("%d", &num);
	ret = Prime(num);
	if (1 == ret)
	{
		printf("是素数\n");
	}
	else if (0 == ret)
	{
		printf("不是素数\n");
	}
	return 0;
}