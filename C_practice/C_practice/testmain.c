#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define Maxsize 100

typedef struct {
	int data[Maxsize];
	int length;  //顺序表的长度，起到一个指针的作用记录最后一个元素在数组中的位置
}SeqList;

////////////////////////////////////////////////////////////////////
/*基本操作的各个函数*/

SeqList* Init_SeqList();       //构建一个空的顺序表L,初始化 
bool Insert_SeqList(SeqList* L, int i, int x);// 插入
int Delete_SeqList(SeqList* L, int i);//删除
int Location_SeqList(SeqList* L, int x);//查找
void show_SeqList(SeqList* L);//打印

////////////////////////////////////////////////////////////////////

int main()
{
	SeqList* L;
	int x, n, m,i;//m为输入元素个数 
	Init_SeqList(&L);//初始化建表
	printf("请输入要输入的元素个数：");
	scanf("%d", &m);
	printf("请输入插入的数据:");
	scanf("%d", &x);
	printf("请输入插入的位置:");
	scanf("%d", &i);
	Insert_SeqList(&L, i, x);
	/*
	for (n = 1; n <= m + 1; n++)
	{
		scanf("%d", L->data[n]);
		L->length++;
	}
	*/
	show_SeqList(L);
	return 0;
}
//初始化 
SeqList* Init_SeqList(SeqList* L)       //构建一个空的顺序表L
{
	L->length = 0;	//表示表中没有元素
}
// 插入
bool Insert_SeqList(SeqList* L, int i, int x)
{
	int j;
	if (L->length == Maxsize - 1)	//表满，不能插入
	{
		printf("表满");   return false;
	}
	if (i<1 || i > L->length + 1)      //检查插入位置的正确性
	{
		printf("位置有误"); return false;
	}
	for (j = L->length; j >= i - 1; j--)	//从最后一位开始移
		L->data[j + 1] = L->data[j];  //移动数据
	L->data[i - 1] = x;	//插入新数据
	L->length++;	//新的表长
	return true;	//插入成功，返回
}
//删除
int Delete_SeqList(SeqList* L, int i)
{
	int j;
	if (i<1 || i>L->length + 1)       //检查空表及删除位置的合法性
	{
		printf("不存在第i个元素");
		return (0);
	}
	for (j = i; j <= L->length; j++)
	{
		L->data[j - 1] = L->data[j];
	}
	L->length--;
	return (1);	//删除成功
}
//查找
int Location_SeqList(SeqList* L, int x)
{
	int i = 0;
	while (i <= L->length && L->data[i] != x)
		i++;
	if (i > L->length) return -1;
	else return i;	//返回存储位置
}
//打印
void show_SeqList(SeqList* L)
{
	int i;
	if (L->length == 0)
	{
		printf("空表！！！");
	}
	else
	{
		printf("线性表：");
		for (i = 1; i < L->length; i++)
		{
			printf("%d->", L->data[i]);
		}
		printf("%d", L->data[i]);
	}
}
/*
#include"common.h"
#include"hashtable.h"

int main()
{	
	int ar[] = { 49, 10, 32, 54, 38, 65, 97, 76, 13, 27 };
	int m = 0;
	int ar[] = { 0 };
	printf("请输入数据个数:\n");
	scanf("%d", &m);
	
	printf("请输入数据:\n");
	for (int i = 0; i <= m; i++)
		scanf("%d", &ar[i]);
	int n = sizeof(ar) / sizeof(int);
	HashTable ht; 
	HashTableInit(ht); 
	for (int i = 0; i < n; ++i)
	{
		HashTableInsert(ht, ar[i]);
	}
	HashTableShow(ht);
	printf("=================\n");
	HashTableRemove(ht, 65);
	HashTableShow(ht);
	return 0;
}
*/