#define _CRT_SECURE_NO_WARNINGS 1


//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void Move(char *p, int k)
//{
//	int len = strlen(p) - 1;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < k; i++)
//	{
//		char tmp = p[0];
//		for (j = 0; j < len; j++)
//		{
//			p[j] = p[j + 1];
//		}
//		p[len] = tmp;
//	}
//}
//
//int main()
//{
//	char arr[] = "ABCD";
//	int k = 0;
//	int sz = strlen(arr) - 1;
//	printf("%s\n", &arr);
//	scanf("%d", &k);
//	Move(arr, k);
//	printf("%s\n", &arr);
//	return 0;
//}



