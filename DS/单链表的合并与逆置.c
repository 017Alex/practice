#include <stdio.h>
#include <stdlib.h>

//创建节点类型
typedef struct node {
	int data;
	struct node* pNext;
} Node;

//函数声明
Node* createLinkedList();
void travel(Node* linkedList);
void sort(Node* linkedList);
Node* getMergeList(Node* linkedList1,Node* linkedList2);
void reverse(Node* linkedList);

int main() {

	//创建链表1并输出
	printf("创建链表1\n");
	Node* linkedList1 = createLinkedList();
	printf("链表1：");
	travel(linkedList1);
	printf("\n");

	//创建链表2并输出
	printf("创建链表2\n");
	Node* linkedList2 = createLinkedList();
	printf("链表2：");
	travel(linkedList2);
	printf("\n");

	//输出合并链表
	printf("合并链表：");
	Node* mergeList = getMergeList(linkedList1,linkedList2);
	travel(mergeList);

	//输出逆序链表
	printf("逆序链表：");
	reverse(mergeList);
	travel(mergeList);

	return 0;
}

//创建链表函数：尾插法
Node* createLinkedList() {
	Node* pHead = (Node*)malloc(sizeof(Node));     //生成头节点
	Node* pTail = pHead;      //定义尾节点，在没有元素时头节点就是尾节点
	Node* pNew = NULL;        //定义新节点

	printf("请输入你要添加数据的个数：");
	int len;
	scanf("%d",&len);
	printf("请输入%d个数：",len);
	for (int i=0; i<len; i++) {
		pNew = (Node *) malloc(sizeof(Node));       //创建新节点
		scanf("%d", &pNew->data);

		pTail->pNext = pNew;    //将新节点挂到尾节点后
		pTail = pNew;           //新节点变成新的尾节点
		pTail->pNext = NULL;    //尾节点后面置空
	}
	return pHead;
}

//遍历链表函数：只要当前节点不为空，就将其打印出来
void travel(Node* linkedList) {
	Node* pTemp = linkedList->pNext;
	while (pTemp != NULL) {
		printf("%d  ",pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

//链表的冒泡排序
void sort(Node* linkedList) {
	for (Node* p = linkedList->pNext; p != NULL; p = p->pNext) {
		for (Node* q = p->pNext; q != NULL; q = q->pNext) {
			if (p->data > q->data) {
				int temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}

//链表的合并：遍历链表1拿到它的尾节点后把链表2挂在后面,再做个排序
Node* getMergeList(Node* linkedList1,Node* linkedList2) {
	Node* pTemp = linkedList1->pNext;
	while (1) {
		if (pTemp->pNext == NULL) {     //拿到尾节点
			pTemp->pNext = linkedList2->pNext;  //把链表2挂上去
			break;
		}
		pTemp = pTemp->pNext;
	}
	sort(linkedList1);      //排序
	return linkedList1;
}

//逆序链表：遍历链表后以头插法重新创建
void reverse(Node* linkedList) {
	Node* pTemp  = linkedList->pNext;
	Node* pNew;
	linkedList->pNext = NULL;

	while (pTemp != NULL) {
		pNew = pTemp;
		pTemp = pTemp->pNext;

		pNew->pNext = linkedList->pNext;
		linkedList->pNext = pNew;
	}
}


