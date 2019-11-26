#pragma once
#include"common.h"

//定义节点
typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

//定义二叉树
typedef struct BinTree
{
	BinTreeNode* root;
}BinTree;

////////////////////////////////////////////////////////////////////////////////////////////
void BinTreeInit(BinTree* t);//初始化二叉树

//创建二叉树
void BinTreeCreate(BinTree* t);
void _BinTreeCreate(BinTreeNode** t);

//前序遍历
void _PreOrder(BinTreeNode* t);
void PreOrder(BinTree* t);
//中序遍历
void InOrder(BinTree* t);
void _InOrder(BinTreeNode* t);
//后序遍历
void PostOrder(BinTree* t);
void _PostOrder(BinTreeNode* t);
//层次遍历
void LevelOrder(BinTree* t);
void _LevelOrder(BinTreeNode* t);

//求节点个数
size_t _Size(BinTreeNode* t);
size_t Size(BinTree* t);

//求二叉树高度
size_t _Height(BinTreeNode* t);
size_t Height(BinTree* t);

//求节点位置
BinTreeNode* _Find(BinTreeNode* t, DataType key);
BinTreeNode* Find(BinTree* t, DataType key);
//求节点双亲
BinTreeNode* _Parent(BinTreeNode* t, DataType key);
BinTreeNode* Parent(BinTree* t, DataType key);
////////////////////////////////////////////////////////////////////////////////////////////

void BinTreeInit(BinTree* t)
{
	t->root = NULL;
}



void BinTreeCreate(BinTree* t)
{
	_BinTreeCreate(&t->root);
}
void _BinTreeCreate(BinTreeNode** t)
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		_BinTreeCreate(&((*t)->leftChild));
		_BinTreeCreate(&((*t)->rightChild));
	}
}



void PreOrder(BinTree* t)
{
	_PreOrder(t->root);
}
void _PreOrder(BinTreeNode* t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		_PreOrder(t->leftChild);
		_PreOrder(t->rightChild);
	}
}

void InOrder(BinTree* t)
{
	_InOrder(t->root);
}
void _InOrder(BinTreeNode* t)
{
	if (t != NULL)
	{
		_InOrder(t->leftChild);
		printf("%c ", t->data);
		_InOrder(t->rightChild);
	}
}

void PostOrder(BinTree* t)
{
	_PostOrder(t->root);
}
void _PostOrder(BinTreeNode* t)
{
	if (t != NULL)
	{
		_PostOrder(t->leftChild);
		_PostOrder(t->rightChild);
		printf("%c ", t->data);
	}
}



size_t Size(BinTree* t)
{
	return _Size(t->root);
}
size_t _Size(BinTreeNode* t)
{
	if (t == NULL)
		return 0;
	else
		return _Size(t->leftChild) + _Size(t->rightChild) + 1;
}



size_t Height(BinTree* t)
{
	return _Height(t->root);
}
size_t _Height(BinTreeNode* t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = _Height(t->leftChild);
		int right_h = _Height(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}



BinTreeNode* Find(BinTree* t, DataType key)
{
	return _Find(t->root, key);
}
BinTreeNode* _Find(BinTreeNode* t, DataType key)
{
	BinTreeNode* p;
	if (t == NULL)
		return NULL;
	if (t->data == key)
		return t;

	p = _Find(t->leftChild, key);
	if (p != NULL)
		return p;
	return _Find(t->rightChild, key);
}


BinTreeNode* Parent(BinTree* t, DataType key)
{
	return _Parent(t->root, key);
}
BinTreeNode* _Parent(BinTreeNode* t, DataType key)
{
	BinTreeNode* pr;
	BinTreeNode* p = _Find(t, key);

	if (t == NULL || p == NULL || p == t)
		return NULL;
	if (t->leftChild == p || t->rightChild == p)
		return t;
	pr = _Parent(t->leftChild, key);
	if (pr != NULL)
		return pr;
	return _Parent(t->rightChild, key);
}

#include"queue.h"
void LevelOrder(BinTree* t)
{
	_LevelOrder(t->root);
}
void _LevelOrder(BinTreeNode* t)
{
	if (t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueueEn(&Q, t);
		while (!LinkQueueEmpty(&Q))
		{
			BinTreeNode* p = LinkQueueFront(&Q);
			LinkQueueDe(&Q);
			printf("%c ", p->data);
			if (p->leftChild != NULL)
				LinkQueueEn(&Q, p->leftChild);
			if (p->rightChild != NULL)
				LinkQueueEn(&Q, p->rightChild);
		}
	}
}











//void BinTreeCreate(BinTree* t)
//{
//	//_BinTreeCreate(&t->root);
//	t->root = _BinTreeCreate_2();
//}
//
//void BinTreeCreate_1(BinTree* t)
//{
//	DataType item;
//	scanf("%c", &item);
//	if (item == '#')
//		*t = NULL;
//	else
//	{
//		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(*t != NULL);
//		(*t)->data = item;
//		BinTreeCreate_1(&((*t)->leftChild));
//		BinTreeCreate_1(&((*t)->rightChild));
//	}
//}
//
//BinTreeNode* BinTreeCreate_2()
//{
//	DataType item;
//	scanf("%c", &item);
//	if (item == '#')
//		return NULL;
//	else
//	{
//		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(t != NULL);
//		t->data = item;
//		t->leftChild = BinTreeCreate_2();
//		t->rightChild = BinTreeCreate_2();
//		return t;
//	}