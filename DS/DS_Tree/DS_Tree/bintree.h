#pragma once
#include"common.h"

typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

typedef BinTreeNode* BinTree;//二级指针BinTree
void BinTreeInit(BinTree* t);//初始化二叉树
void BinTreeCreate_1(BinTree* t);//创建二叉树（方法1）
BinTreeNode* BinTreeCreate_2();//创建二叉树（方法2）

void BinTreeInit(BinTree* t)
{
	t = NULL;
}

void BinTreeCreate_1(BinTree* t)
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate_1(&((*t)->leftChild));
		BinTreeCreate_1(&((*t)->rightChild));
	}
}

BinTreeNode* BinTreeCreate_2()
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = BinTreeCreate_2();
		t->rightChild = BinTreeCreate_2();
		return t;
	}