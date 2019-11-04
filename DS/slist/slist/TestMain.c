#include"common.h"

/*typedef struct SListNode//创建节点
{
	DataType data;
	struct SListNode* next;
}SListNode;

SListNode* CreateSList()
{
	SListNode* first = (SListNode*)malloc(sizeof(SListNode));
	SListNode* last = first;
	SListNode* new = NULL;
	int i = 0;
	int size = 0;
	printf("数据个数:>");
	scanf("%d", &size);
	printf("请输入数据 :>");
	for (i = 0; i < size; i++)
	{
		new = (SListNode*)malloc(sizeof(SListNode));
		scanf("%d", &new->data);
		last->next = new;
		last = new;
		last->next = NULL;
	}
	return first;
}

void ShowList(SListNode* list1)
{
	SListNode* tem = list1->next;
	while (tem != NULL) {
		printf("%d  ", tem->data);
		tem = tem->next;
	}
	printf("\n");
}

SListNode* GetMergeList(SListNode* list1, SListNode* list2)
{
	SListNode* tem = list1->next;
	while (1)
	{
		if (tem->next == NULL)
		{
			tem->next = list2->next;
			break;
		}
		tem = tem->next;
	}
	return list1;
}

void Reverse(SListNode* list)
{
	SListNode* tem = list->next;
	SListNode* new;
	list->next = NULL;
	while (tem != NULL)
	{
		new = tem;
		tem = tem->next;
		new->next = list->next;
		list->next = new;
	}
}


int main()
{
	//创建链表1
	printf("创建链表1:\n");
	SListNode* list1 = CreateSList();
	printf("链表1:\n");
	ShowList(list1);//显示链表
	printf("\n");
	//创建链表2
	printf("创建链表2\n");
	SListNode* list2 = CreateSList();
	printf("链表2:\n");
	ShowList(list2);
	printf("\n");
	//合并链表
	printf("合并链表:");
	SListNode* list = GetMergeList(list1, list2);
	ShowList(list);
	//逆置链表
	printf("逆置链表:\n");
	Reverse(list);
	ShowList(list);
	return 0;
}*/



#include"slist.h"

int main()
{
	SList mylist;
	SListInit(&mylist);
	int select = 1;
	SListNode* p;
	int pos;
	DataType item,key;
	DataType ret = 0;
	bool flag = 0;
	while (select)
	{
		printf("*****************************************\n");
		printf("* [1] push_back         [2] push_front  *\n");//1尾插   2头插
		printf("* [3] show_list         [4] pop_back    *\n");//3展示链表   4尾删
		printf("* [5] pop_front         [6] insert_pos  *\n");//5头删
		printf("* [7] insert_val        [8] delete_pos  *\n");
		printf("* [9] delete_val        [10] find_pos   *\n");
		printf("* [11] find_val         [12] sort       *\n");
		printf("* [13] reverse          [14] length     *\n");
		printf("* [15] clear            [16] modify_pos *\n");//15清空链表
		printf("* [17] modify_val       [18] capacity   *\n");
		printf("* [0] quit_system                       *\n");
		printf("*****************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&mylist, item);
			}
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的位置:>");
			scanf("%d", &pos);
			//flag = SeqListFindByPos(&mylist, pos, &ret); //true false
			if (flag)
				printf("查找的数据为:> %d\n", ret);
			else
				printf("查找的数据不存在.\n");
			break;
		case 11:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = SListFindByVal(&mylist, key);
			if (pos == -1)
				printf("查找的数据不存在.\n");
			else
				printf("数据所在的下标为:> %d\n", pos);
			break;
		case 12:
			SListSort(&mylist);
			break;
		case 13:
			SListReverse(&mylist);
			break;
		case 14:
			//printf("SeqList Length = %d\n", SListLength(&mylist));
			break;
		case 15:
			SListClear(&mylist);
			break;
		case 18:
			//printf("capacity = %d\n", SeqListCapacity(&mylist));
			break;
		default:
			printf("输入错误，请重新输入......\n");
			break;
		}
	system("pause");
	system("cls");//清屏
	
	}

	SListDestroy(&mylist);
	return 0;
}