#include"bintree.h"

int main()
{
	BinTree bt;
	BinTreeInit(&bt);//初始化二叉树
	//BinTreeCreate_1(&bt);//创建二叉树1
	bt = BinTreeCreate_2();//创建二叉树2
	return 0;
}