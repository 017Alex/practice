#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<assert.h>

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


//
//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int sum = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum += ((value >> 1) & 1) * pow(2, 31 - i);
//	}
//	return sum;
//}

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
//	unsigned int num = 0;
//	scanf("%d", &num);
//	unsigned int ret = reverse_bit(num);
//	printf("%u\n", ret);
//	return 0;
//}
//



//int main()
//{
//	int a = 0;
//	int b = 0;
//	int ret = 0;
//	scanf("%d %d", &a, &b);
//	ret = (a - b) / 2 + b;       //ret = a+((b-a)>>1);      //ret = (a&b)+((a^b)>>1);
//	printf("%d\n", ret);
//	return 0;
//}





//int main()
//{
//	int i = 0;
//	int ret = 0;
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	printf("%d\n", ret);
//	return 0;
//}




int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);

}

reverse_string(char* left, char* right)
{
	assert(lest && right)
		while (left < right)
		{
			char tmp = *left;
			*left = *right;
			*right = tmp;
			left++;
			right--;
		}
}

void reverse(char arr[])
{
	//1.逆序整个数组
	char* start;
	char* end;
	int len = my_strlen(arr);
	reverse_string(arr, arr + len - 1);
	//2.逆序每个单词
	start = arr;
	end = start;
	while(*end)
	{
		start = end;
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		reverse_string(start, end - 1);
		end++;
	}
}

int main()
{
	char arr[] = "student a am i";
	reverse(arr);
	printf("%s\n", arr);
	return 0;
}