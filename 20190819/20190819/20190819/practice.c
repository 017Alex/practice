#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//1.写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数
//}
//
//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
//
//3. 输出一个整数的每一位。
//
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7



//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while (value != 0)
//	{
//		if (1 == value % 2)
//		{
//			count++;
//		}
//		value /= 2;
//	}
//	return count;
//}
//
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	printf("%d\n", count_one_bits(num));
//	return 0;
//}





//int main()
//{
//	int i = 0;
//	int num = 0;
//	scanf("%d", &num);
//	printf("奇数：");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d", (num >> i) & 1);
//	}
//	printf("\n奇数：");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (num >> i) & 1);
//	}
//	printf("\n");
//	return 0;
//}



//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	while (num)
//	{
//		printf("%d ", num % 10);
//		num /= 10;
//	}
//	return 0;
//}




int Fun(int n1, int n2)
{
	int count = 0;
	int i = 0;
	while (i < 32)
	{
		if ((n1 & 1) != (n2 & 1))
			count++;
		n1 >>= 1;
		n2 >>= 1;
		i++;
	}
	return count;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d%d", &num1, &num2);
	printf("%d", Fun(num1, num2));
	return 0;
}