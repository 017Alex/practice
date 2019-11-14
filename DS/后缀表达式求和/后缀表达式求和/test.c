#include"common.h"

//创建栈结构
typedef struct StackNode
{
	DataType data;
	struct StackNode* next;
}StackNode;

typedef StackNode* ListStack;

//////////////////////////////////////////////函数声明
//bool ListStackEmpty(ListStack* pst);
void ListStackInit(ListStack* pst);
//void ListStackShow(ListStack pst);
void ListStackPush(ListStack* pst, DataType x);
void ListStackPop(ListStack* pst);
DataType ListStackTop(ListStack* pst);

//////////////////////////////////////////////函数实现
int main()
{
	ListStack* stack = (ListStack*)malloc(sizeof(StackNode));
	int data, x, y;
	char ar[20] = { 0 };

	ListStackInit(stack);
	printf("请输入后缀表达式：");
	gets(ar);

	for (int i = 0; ar[i] != '\0'; i++)
	{
		if (ar[i] >= '0' && ar[i] <= '9')
		{
			data = ar[i] - 48;
			ListStackPush(stack, data);
		}
		else
		{
			y = ListStackTop(stack);
			ListStackPop(stack);
			x = ListStackTop(stack);
			ListStackPop(stack);

			switch (ar[i])
			{
			case '+':
				ListStackPush(stack, x + y);
				break;
			case '-':
				ListStackPush(stack, x - y);
				break;
			case '*':
				ListStackPush(stack, x * y);
				break;
			case '/':
				ListStackPush(stack, x / y);
				break;
			}
		}
	}
	printf("结果为：%d", ListStackTop(stack));
	return 0;
}


////判断栈空
//bool ListStackEmpty(ListStack* pst)
//{
//	return *pst == NULL;
//}

//初始化栈
void ListStackInit(ListStack* pst)
{
	*pst = NULL;
}

//取栈顶元素
DataType ListStackTop(ListStack* pst)
{
	assert(*pst != NULL);
	return (*pst)->data;
}

//压栈
void ListStackPush(ListStack* pst, DataType x)
{
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	assert(node != NULL);
	node->data = x;

	node->next = *pst;
	*pst = node;
}

//出栈
void ListStackPop(ListStack* pst)
{
	StackNode* p = *pst;
	*pst = p->next;
	free(p);
}

////展示栈
//void ListStackShow(ListStack pst)
//{
//	StackNode* p = pst;
//	while (p != NULL)
//	{
//		printf("%d\n", p->data);
//		p = p->next;
//	}
//}