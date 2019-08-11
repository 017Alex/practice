//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int a;
//	int b;
//	int c;
//	scanf("%d%d", &a, &b);
//	c = a;
//	a = b;
//	b = c;
//	printf("%d %d", a, b);
//	return 0;
//}
//
//
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int a;
//	int b;
//	scanf("%d%d", &a, &b);
//	b = b - a;
//	a = a + b;
//	b = a - b;
//	printf("%d %d", a, b);
//	return 0;
//}
//
//
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int arr[10];
//	int i = 0;
//	int flag = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	i = 0;
//	while (i <= 10)
//	{
//		if (arr[i] >= flag)
//		{
//			flag = arr[i];
//		}
//		i++;
//	}
//	printf("%d", flag);
//	return 0;
//}
//
//
//
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int a;
//	int b;
//	int c;
//	int flag;
//	scanf("%d%d%d", &a, &b, &c);
//	if (c > b)
//	{
//		flag = c;
//		c = b;
//		b = flag;
//	}
//	if (b > a)
//	{
//		flag = a;
//		a = b;
//		b = flag;
//	}
//	if (c > b)
//	{
//		flag = c;
//		c = b;
//		b = flag;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//
//
//

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a % b;
	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}
	printf("%d", b);
	return 0;
}

