#pragma once
#include"common.h"

#define MAXSIZE 10

typedef struct SeqList
{
	DataType elem[MAXSIZE];
	size_t length; //size_t = unsigned int
}SeqList;

//////////////////////////////////////////////////////////////////////
//声明
void SeqListInit(SeqList* l);
bool SeqListInsert(SeqList* l, int i, DataType x);
void ShowSeqList(SeqList* l);


//////////////////////////////////////////////////////////////////////
//实现
void SeqListInit(SeqList* l)
{
	l->length = 0;
}

void ShowSeqList(SeqList* l)
{
	int i = 0;
	for (i = 0; i < l->length; i++)
	{
		printf("%d->",l->elem[i + 1]);
	}
}

bool SeqListInsert(SeqList* l, int i, DataType x)
{
	int j = 0;
	if (l->length == MAXSIZE - 1)
	{
		printf("表已满！\n");
		return false;
	}
	if (i < 1 || i > l->length + 1)
	{
		printf("位置有误！\n");
		return false;
	}
	for (j = l->length; j >= i; j--)
		l->elem[j + 1] = l->elem[j];
	l->elem[i] = x;
	l->length++;
	return true;
}
















