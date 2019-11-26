#pragma once
#include"bintree.h"

#define QueueDataType BinTreeNode*

//链式队列
typedef struct LinkQueueNode
{
	QueueDataType data;
	struct LinkQueueNode* next;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode* front;
	LinkQueueNode* tail;
}LinkQueue;

//////////////////////////////////////////////////////////////////////
void LinkQueueInit(LinkQueue* Q);//初始化队列
void LinkQueueEn(LinkQueue* Q, QueueDataType x);//入队
bool LinkQueueEmpty(LinkQueue* Q);//判断队列为空
QueueDataType LinkQueueFront(LinkQueue* Q);//取队头元素
void LinkQueueDe(LinkQueue* Q);//出队
//////////////////////////////////////////////////////////////////////
void LinkQueueInit(LinkQueue* Q)
{
	Q->front = Q->tail = NULL;
}

void LinkQueueEn(LinkQueue* Q, QueueDataType x)
{
	LinkQueueNode* s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	if (LinkQueueEmpty(Q))
	{
		Q->front = Q->tail = s;
	}
	else
	{
		Q->tail->next = s;
		Q->tail = s;
	}
}

bool LinkQueueEmpty(LinkQueue* Q)
{
	return Q->front == NULL;
}

QueueDataType LinkQueueFront(LinkQueue* Q)
{
	if (LinkQueueEmpty(Q))
	{
		printf("队列已空， 不能取对头元素.\n");
		return;
	}
	return Q->front->data;
}

void LinkQueueDe(LinkQueue* Q)
{
	if (LinkQueueEmpty(Q))
	{
		printf("队列已空， 不能出队.\n");
		return;
	}
	LinkQueueNode* p = Q->front;
	Q->front = Q->front->next;
	free(p);
}
