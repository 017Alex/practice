#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
//
//2.不使用（a + b） / 2这种方式，求两个数的平均值。
//
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//
//4.
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。


//unsigned int reverse_bit(unsigned int value)
//{
//	int arr[32] = { 0 };
//	int i = 0;
//	unsigned int sum = 0;
//	for (i = 0; i < 32; i++)
//	{
//		arr[i] = value & 1;
//		value = value >> 1;
//	}
//	for (i = 0; i < 32; i++)
//	{
//		sum += arr[i] * pow(2, 32 - 1 - i);
//	}
//	return sum;
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	unsigned int ret = reverse_bit(num);
//	printf("%u\n", ret);
//	return 0;
//}




int main()
{
	int a = 0;
	int b = 0;
	int ret = 0;
	scanf("%d %d", &a, &b);
	ret = (a - b) / 2 + b;
	printf("%d\n", ret);
	return 0;
}