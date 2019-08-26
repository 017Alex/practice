#define _CRT_SECURE_NO_WARNINGS 1

//1.实现strcpy
//2.实现strcat
//3.实现strstr
//4.实现strchr
//5.实现strcmp
//6.实现memcpy
//7.实现memmove

#include<stdio.h>
#include<assert.h>

char* My_strcpy(char* arr2, const char* arr1)
{
	char* ret = arr2;
	assert(arr2 != NULL && arr1 != NULL);
	while (*arr2++ = *arr1++)
	{
		;
	}
	return ret;
}

char* My_strcat(char* arr3, const char* arr1)
{
	char* ret = arr3;
	assert(arr3 != NULL && arr1 != NULL);
	while (*arr3 != '\0')
	{
		arr3++;
	}
	while (*arr3++ = *arr1++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[20] = "abcdef";
	char arr2[20] = { 0 };
	char arr3[20] = "123456";
	printf("%s\n", My_strcpy(arr2, arr1));
	printf("%s\n", My_strcat(arr3, arr1));
	return 0;
}