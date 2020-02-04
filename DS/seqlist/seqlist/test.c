#include"common.h"
#include"seplist.h"

int main()
{
	SeqList mylist;
	SeqListInit(&mylist);
	int select = 1;
	int i, x;
	while (select)
	{
		printf("***********************************\n");
		printf("*1.插入数据         2.求线性表长度*\n");
		printf("*3.按值查找         4.按值删除    *\n");
		printf("*5.显示顺序表                     *\n");
		printf("*            按0退出              *\n");
		printf("***********************************\n");
		printf("请选择:");
		scanf("%d", &select);
		if (0 == select)
			break;
		switch (select)
		{
		case 1:
			printf("请输入插入的数据:");
			scanf("%d",&x);
			printf("请输入插入的位置:");
			scanf("%d", &i);
			SeqListInsert(&mylist, i, x);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			ShowSeqList(&mylist);
			break;
		default:
			printf("输入错误，请重新输入！！\n");
		}
		system("pause");
		system("cls");
	}
	return 0;
}