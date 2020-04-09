#include <stdio.h>

int main()
{
	// TODO 请在此处编写代码，完成题目要求
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
	case '3':
	case '5':
	case '7':
	case '8':
	case '10':
	case '12':
		printf("solar month\n");
		break;
	case '2':
	case '4':
	case '6':
	case '9':
	case '11':
		printf("lunar month\n");
		break;
	default:
		printf("error\n");
		break;
	}
	return 0;
}















//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222

//在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，其各个数之N次方和等于该数。
//例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
//153 = 1^3 + 5^3 + 3^3。   
//370 = 3^3 + 7^3 + 0^3。
//371 = 3^3 + 7^3 + 1^3。
//407 = 4^3 + 0^3 + 7^3。

//pow(2,3)   2^3   math.h

/*
#include<stdio.h>
#include<math.h>


int main() {
	float b;
	b = 4.7;
	printf("b=%d\n", b);
	return 0;
}
/*
int main()
{
	int i;
	//遍历
	for (i = 100; i <= 999; i++)
	{
		if (pow(i / 100, 3) + pow(i % 100 / 10, 3) + pow(i % 10, 3) == i)
		{
			printf("%d ", i);
		}
	}

	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	double r, c, s;
	double PI = 3.14159;
	scanf("%f", &r);
	c = 2 * PI * r;
	s = PI * r * r;
	printf("周长: %f\n面积: %f\n", c, s);
	return 0;
}
*/


/*
#include <stdio.h>
#include <math.h>

int main()
{
	// TODO 请在此处编写代码，完成题目要求
	int i;
	int num;
	scanf("%d", &num);
	for (i = 100; i <= num; i++)
	{
		if (pow(i / 100, 3) + pow(i % 100 / 10, 3) + pow(i % 10, 3) == i)
		{
			printf("%d", i);
		}
	}
	return 0;
}


/*
#include<stdio.h>
#include<math.h>

int main()
{
	int i;
	//遍历
	for (i = 100; i <= 999; i++)
	{
		if (pow(i / 100, 3) + pow(i % 100 / 10, 3) + pow(i % 10, 3) == i)
		{
			printf("%d ", i);
		}
	}

	return 0;
}
*/














/*
#include<stdio.h>

int main()
{
	int a ;
	int sum = 0;
	int i;
	scanf("%d",&a);
	for (i = 1; i <= 5; i++)
	{
		sum = a + sum;
		a = (a * 10 + a);
		printf("a = %d\n", a);
	}
	printf("%d", sum);
	return 0;
}
*/




















/*
#include <stdio.h>
#include<math.h>

void Swap(int* x, int* y)
{
	int tem = 0;
	tem = *x;//解引用
	*x = *y;
	*y = tem;
}

int main()
{
	int a = 100;
	int b = 200;
	Swap(&a, &b);
	printf("a = %d, b = %d", a, b);
	return 0;
}









/*
int main()
{
	int sum = 0;
	int num = 1;
	int sum2 = 0;
	int num2 = 2;
	while (num < 100)
	{
		sum = num + sum;
		num = num + 2;
	}
	printf("奇数和为%d\n", sum);

	while (num2 <= 100)
	{
		sum2 = num2 + sum2;
		num2 = num2 + 2;
	}
	printf("偶数和为%d\n", sum2);

	return 0;
}



/*
int main()
{
	int arr[100];
	int i;
	for (i = 0; i <100; i++)
	{
		arr[i] = i+1;//arr[0]=1   arr[1]=2
	}
	for (i = 0; i < 100; i++)
	{
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	return 0;
}
*/


/*
void Swap(int x, int y)
{
	int tem = 0;
	tem = x;
	x = y;
	y = tem;
}

int main()
{
	int a = 100;
	int b = 200;
	Swap(a,b);
	printf("a = %d, b = %d",a,b);
	return 0;
}



/*
int main()
{
	int n = 2;
	int k = 3;
	int c = 0;
	c = pow(2, 3);
	printf("%d", c);
	return 0;
}
*/












/*
int main()//使用 while, for 分别输 1~100 以内的所有的奇数和偶数的和：
{
	int sum = 0;
	int num = 1;
	int sum2 = 0;
	int num2 = 2;
	for (num=1;num<100;num=num+2)
	{
		sum = sum + num;
	}
	printf("奇数和为：%d\n", sum);

	for (num2 = 2; num2 <= 100; num2 = num2 + 2)
	{
		sum2 = num2 + sum2;
	}
	printf("偶数和为：%d\n", sum2);



	
	int sum = 0;
	int num = 1;
	int sum2 = 0;
	int num2 = 2;
	while (num < 100)
	{
		sum = num + sum;
		num = num + 2;
	}
	printf("奇数和为%d\n", sum);

	while (num2 <= 100)
	{
		sum2 = num2 + sum2;
		num2 = num2 + 2;
	}
	printf("偶数和为%d\n", sum2);
	
	return 0;
}









/*
{
	int i = 1;
	for (; i <= 10; i++)
	{
		if (i == 5)
			continue;
		printf("%d ", i);
	}
	return 0;
}
//代码1
/*
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (5 == i)
			break;
		printf("%d ", i);
	}
	return 0;
}


/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", i);
	}
	/*
	int i = 1;
	while (i <= 10)
	{
		i = i + 1;
		if (i == 5)
			continue;
		printf("%d ", i);
		
	}
	/*
	int n = 1;
	int m = 2;//n = 1
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)
		{//switch允许嵌套使用
		case 1:
			n++;
		case 2:
			m++;
			n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m = %d, n = %d\n", m, n);
	*/
//	return 0;
//}








/*
int main()
{
	int i;
	int sum = 0;
	for (i = 0; i <= 100; i++)
	{
		sum += i;
	}
	printf("%d\n", sum);
	return 0;
}






/*
int main()
{
	int a = 11;
	do
	{
		printf("%d\n", a);
		a += 1;
	} while (a > 10);
	return 0;
}

/*
int main()
{
	int a = 0;
	while (a > 10)
	{
		printf("%d", a);
		a += 1;
	}
	return 0;
}




/*
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a > b&& a > c)
	{
		printf("a的值为%d\n", a);
	}
	if (b > a&& b > c)
	{
		printf("b的值为%d\n", b);
	}
	if (c > a&& c > b)
	{
		printf("c的值为%d\n", c);
	}
	if (a == b && a == c)
	{
		printf("abc相等");
	}
	return 0;
}




/*
#include<stdio.h>


int IsBig(int a, int b)
{
	return a >= b ? a : b;
}

void main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d", &a);
	scanf("%d", &b);
	c = IsBig(a, b);
	printf("%d\n",c);
}












//int global = 2019;//全局变量
//int main()
//{
//	int local = 2018;//局部变量
//	//下面定义的global会不会有问题？
//	int global = 2020;//局部变量
//	printf("global = %d\n", global);
//	return 0;
//}
////当局部变量和全局变量同名的时候，局部变量优先使用














//#include<stdio.h>//头文件
//
//int main()//主函数
//{
//	printf("%d\n", a);
//	//int a, b;
//	//a = 1;
//	//b = 2;
//	//if (a == b)//1 0                  1 真            0  假  
//	//	printf("相等\n");
//	//else
//	//	printf("不等\n");
//
//	//int a = 1;
//	//--a;
//	//printf("%d\n", a);//% 模 
//	/*
//		printf  标准输出函数
//		""  输出字符串
//		\n  换行（转义字符）
//	*/
//	return 0;//返回值（0 空值）
//			//返回值为空
//}

//{}函数

/*

	块注释

*/

//行注释