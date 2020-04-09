/*
#include"common.h"
#include<iostream>
using namespace std;

#define int_max 10000 
#define inf 9999  
#define max 20 
#define MAX 20 
#define M 20 

typedef struct ArcCell
{
	int adj; char* info;
}ArcCell, AdjMatrix[20][20];

typedef struct
{
	char vexs[20]; AdjMatrix arcs; int vexnum, arcnum;
}MGraph;

int localvex(MGraph G, char v)
{
	int i = 0; while (G.vexs[i] != v) { ++i; } return i;
}

void ljjzprint(MGraph G)
{
	int i, j, n = 0;
	printf("建立的邻接矩阵如下\n");
	printf("\n");
	printf(" _____________________________________________\n");
	for (i = 0; i != G.vexnum; i++)
	{  
		for (j = 0; j != G.vexnum; j++)
		{
			if (j == 0)printf("                  ");
			printf("%d", G.arcs[i][j].adj); printf("       "); n++;
			if (n == G.vexnum) { printf("\n"); n = 0; }
		}
	}
	printf(" ______________________________________________\n");
}

int creatMGraph(MGraph& G)
{
	char v1, v2;
	int i, j, w;
	printf("建立邻接矩阵:\n");
	printf("请输入图G顶点城市和弧边的个数:");
	scanf("%d", &G.vexnum);
	scanf("%d", &G.arcnum);
	printf("输入所有顶点:"); 
		for (i = 0; i < G.vexnum; ++i)
		{
			scanf("%d", &G.vexs[i]);
		}
		for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j].adj = int_max;
			G.arcs[i][j].info = NULL;
		}
	printf("输入所有边及依附的顶点城市和权距离:\n");
	for (int k = 0; k < G.arcnum; k++)
	{
		scanf("%c", &v1);
		scanf("%c", &v2);
		scanf("%d", &w);
		i = localvex(G, v1);
		j = localvex(G, v2);
		G.arcs[i][j].adj = w;
		G.arcs[j][i].adj = w;
	}
	ljjzprint(G);
	printf("图G邻接矩阵创建成功\n");
	return G.vexnum;
}

int visited[max];
int we;

typedef struct arcnode
{
	int adjvex;
	struct arcnode* nextarc;
	char* info;
}arcnode;

typedef struct vnode
{
	char data;
	arcnode* firstarc;
}vnode, adjlist;

typedef struct//图的定义 
{
	adjlist vertices[max];
	int vexnum, arcnum;
	int kind;
}algraph;

int prim(int g[][max], int n) //最小生成树PRIM算法 
{
	int lowcost[max], prevex[max];
	int i, j, k, min;
	int sum = 0;
	for (i = 2; i <= n; i++)
	{
		lowcost[i] = g[1][i];
		prevex[i] = 1;
	}
	lowcost[1] = 0;
	for (i = 2; i <= n; i++)
	{
		min = inf;
		k = 0;
		for (j = 2; j <= n; j++)
			if ((lowcost[j] < min) && (lowcost[j] != 0))
			{
				min = lowcost[j];
				k = j;
			}
		printf("(%d,%d)%d\t", prevex[k] - 1, k - 1, min);
		sum += min; lowcost[k] = 0;
		for (j = 2; j <= n; j++)  if (g[k][j] < lowcost[j])
		{
			lowcost[j] = g[k][j];
			prevex[j] = k;
		}
		printf("\n");
	}
	printf("最少生成树的代价:");
	printf("%d",sum);
	return 0;
}
typedef struct 
{
	int begin;
	int end;
	int weight;
}edge;

typedef struct 
{
	int adj;
	int weight;
}Adj[MAX][MAX];

typedef struct
{
	Adj arc;
	int vexnum, arcnum;
}MGraphA;

void CreatGraph(MGraphA*);//函数申明 
void sort(edge*, MGraphA*);
void MiniSpanTree(MGraphA*);
int  Find(int*, int);
void Swapn(edge*, int, int);

void CreatGraph(MGraphA* D)//构件图 
{
	int i, j, n, m;
	printf("请输入边数和顶点数:");
	scanf("%d %d", &D->arcnum, &D->vexnum);
	for (i = 1; i <= D->vexnum; i++)//初始化图 
	{
		for (j = 1; j <= D->vexnum; j++) {
			D->arc[i][j].adj = D->arc[j][i].adj = 0;
		}
	}
	for (i = 1; i <= D->arcnum; i++)//输入边和权值 
	{
		printf("\n请输入有边的2个顶点");
		scanf("%d %d", &n, &m);
		while (n < 0 || n > D->vexnum || m < 0 || n > D->vexnum)
		{
			printf("输入的数字不符合要求 请重新输入:");
			scanf("%d%d", &n, &m);
		}
		D->arc[n][m].adj = D->arc[m][n].adj = 1;
		getchar();
		printf("\n请输入%d与%d之间的权值:", n, m);
		scanf("%d", &D->arc[n][m].weight);
	}
	printf("邻接矩阵为:\n");
	for (i = 1; i <= D->vexnum; i++)
	{
		for (j = 1; j <= D->vexnum; j++)
		{
			printf("%d ", D->arc[i][j].adj);
		}
		printf("\n");
	}
}
void sort(edge edges[], MGraphA* D)//对权值进行排序 
{
	int i, j;
	for (i = 1; i < D->arcnum; i++)
	{
		for (j = i + 1; j <= D->arcnum; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{ Swapn(edges, i, j); }
		}
	}
	printf("权排序之后的为:\n");
	for (i = 1; i < D->arcnum; i++)
	{
		printf("<< %d, %d >>   %d\n", edges[i].begin, edges[i].end,edges[i].weight);
	}
}

void Swapn(edge* edges, int i, int j)//交换权值以及头和尾 
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

void MiniSpanTree(MGraphA* D)//生成最小生成树
{
	int i, j, n, m, SUM = 0;
	int k = 1;
	int parent[M];
	edge edges[M];
	for (i = 1; i < D->vexnum; i++)
	{
		for (j = i + 1; j <= D->vexnum; j++)
		{
			if (D->arc[i][j].adj == 1)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = D->arc[i][j].weight;
				k++;
			}
		}
	}
	sort(edges, D);
	for (i = 1; i <= D->arcnum; i++)
	{
		parent[i] = 0;
	}   
	printf("最小生成树为:\n");
	for (i = 1; i <= D->arcnum; i++)//核心部分 
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)
		{
			parent[n] = m; printf("<< %d, %d >>   %d\n",
				edges[i].begin, edges[i].end, edges[i].weight);
			SUM = SUM + edges[i].weight;
		}
	}
	printf("最少生成树的代价:%d",SUM);
}

int Find(int* parent, int f)//找尾 
{
	while (parent[f] > 0)
	{ 
		f = parent[f]; 
	}
	return f;
}

void main()
{
	algraph gra;
	MGraph G;
	MGraphA* D;
	int i, d, m, g[20][20];
	char a = 'a';
	int s;
	char y = 'y';
	while (y = 'y') 
	{
		printf("           …………最小生成树的求法…………\n");
		printf("       ____________________________________________\n");
		printf("      |     1.建立邻接矩阵(无向图)                 |\n");
		printf("      |     2.用prim算法求最小生成树(无向图)       |\n");
		printf("      |     3.用kruskal算法求最小生成树            |\n");
		printf("      |___________________________________________ |\n");
		printf("      请选择相应的菜单(1-3):");
		scanf("%d",&s);
		switch (s)
		{
		case 1:
			d = creatMGraph(G);
			vnode v;
			printf("\n注意若该图为非强连通图(含有多个连通分量)时\n最小生成树不存在,则显示为非法值\n\n");
			break;
		case 2:
			printf("prim算法求解如下\n");
			for (i = 0; i != G.vexnum; ++i)
				for (int j = 0; j != G.vexnum; ++j)
					g[i + 1][j + 1] = G.arcs[i][j].adj;
			prim(g, d);
			break;
		case 3:
			printf("kruskal算法求解如下\n");
			D = (MGraphA*)malloc(sizeof(MGraphA));
			CreatGraph(D);
			MiniSpanTree(D);
			break;
		}
		printf("\n\n是否继续y/n:");
		scanf("%d", &y);
		if (y == 'n')
			break;
	}
}
*/





















//#include<stdio.h>
//#include<stdlib.h>
//
//#define MaxVertexNum 100
//#define ERROR 0
//#define OK 1
//#define FALSE 0
//#define TRUE 1
//
//typedef int Boolean;
//typedef int VertexType;
//Boolean visit[MaxVertexNum];
//typedef struct node
//{
//	int adjvex;
//	struct node* next;
//}EdgeNode;
//
//typedef struct
//{
//	VertexType vertex;
//	EdgeNode* firstedge;
//}VertexNode;
//
//typedef VertexNode AdjList[MaxVertexNum];
//
//typedef struct
//{
//	AdjList adjlist;
//	int n, e;
//}ALGraph;
//
//int FindVertex(ALGraph* G, int e, int n)
//{
//	int i;
//
//	for (i = 0; i < n; i++)
//	{
//		if (G->adjlist[i].vertex == e)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//void create(ALGraph* G)//创建邻接表
//{
//	int i, j, k, w, v;
//	EdgeNode* s;
//
//	printf("读入顶点和边数");
//	scanf("%d %d", &G->n, &G->e);
//
//	for (i = 0; i < G->n; i++)
//	{
//
//		printf("建立顶点表");
//		fflush(stdin);
//		scanf("%d", &G->adjlist[i].vertex);
//		G->adjlist[i].firstedge = NULL;
//	}
//	printf("建立边表\n");
//	for (k = 0; k < G->e; k++)
//	{
//		printf("读入(vi-vj)的顶点对序号");
//		scanf("%d %d", &i, &j);
//
//		i = FindVertex(G, i, G->n);
//		j = FindVertex(G, j, G->n);
//		if (i == -1 || j == -1)
//		{
//			printf("找不到顶点，请重新输入!\n");
//			printf("读入(vi-vj)的顶点对序号");
//			scanf("%d %d", &i, &j);
//			i = FindVertex(G, i, G->n);
//			j = FindVertex(G, j, G->n);
//		}
//		s = (EdgeNode*)malloc(sizeof(EdgeNode));
//		s->adjvex = (j);
//		s->next = G->adjlist[i].firstedge;
//		G->adjlist[i].firstedge = s;
//	}
//}
//
//void TopoSort(ALGraph* G, int n)
//{
//	int i, j, k, top, m = 0;
//	EdgeNode* p;
//	int* d = (int*)malloc(n * sizeof(int));
//	for (i = 0; i < n; i++)		//初始化数组
//	{
//		d[i] = 0;
//	}
//	for (i = 0; i < n; i++)		//统计各个顶点的入度情况，并把他们填入数组里面
//	{
//		p = G->adjlist[i].firstedge;
//		while (p != NULL)
//		{
//			j = p->adjvex;
//			d[j]++;
//			p = p->next;
//		}
//	}
//	top = -1;
//	for (i = 0; i < n; i++)			//先找出里面入度是0的顶点
//	{
//		if (d[i] == 0)
//		{
//			d[i] = top;
//			top = i;
//		}
//	}
//
//	while (top != -1)
//	{
//		j = top;
//		top = d[top];
//		printf("%d ", j);
//		m++;		//统计顶点
//		p = G->adjlist[j].firstedge;
//		while (p)
//		{
//			k = p->adjvex;		//相l连接的顶点
//			d[k]--;		//相连接的顶点入度减1
//			if (d[k] == 0)		//如果发现入度为0的新顶点，从该顶点出发
//			{
//				d[k] = top;
//				top = k;
//			}
//			p = p->next;
//		}
//
//	}
//	if (m < n) printf("\n有回路！\n");
//	free(d);
//}
//
//void main()
//{
//	ALGraph* G = (ALGraph*)malloc(sizeof(ALGraph));
//	EdgeNode* p;
//	create(G);
//	int i;
//	printf("其邻接表为('->'表示两个之间有连接)：\n");
//	for (i = 0; i < G->n; i++)
//	{
//		p = G->adjlist[i].firstedge;
//		printf("%d->", G->adjlist[i].vertex);
//		while (p != NULL)
//		{
//			printf("%d->", G->adjlist[p->adjvex].vertex);
//			p = p->next;
//		}
//		printf("\n");
//	}
//	printf("拓扑排序为：\n");
//	TopoSort(G, G->n);
//}

















//#include"common.h"
//
////创建栈结构
//typedef struct StackNode
//{
//	DataType data;
//	struct StackNode* next;
//}StackNode;
//
//typedef StackNode* ListStack;
//
////////////////////////////////////////////////函数声明
////bool ListStackEmpty(ListStack* pst);
//void ListStackInit(ListStack* pst);
////void ListStackShow(ListStack pst);
//void ListStackPush(ListStack* pst, DataType x);
//void ListStackPop(ListStack* pst);
//DataType ListStackTop(ListStack* pst);
//
////////////////////////////////////////////////函数实现
//int main()
//{
//	ListStack* stack = (ListStack*)malloc(sizeof(StackNode));
//	int data, x, y;
//	char ar[20] = { 0 };
//
//	ListStackInit(stack);
//	printf("请输入后缀表达式：");
//	gets(ar);
//
//	for (int i = 0; ar[i] != '\0'; i++)
//	{
//		if (ar[i] >= '0' && ar[i] <= '9')
//		{
//			data = ar[i] - 48;
//			ListStackPush(stack, data);
//		}
//		else
//		{
//			y = ListStackTop(stack);
//			ListStackPop(stack);
//			x = ListStackTop(stack);
//			ListStackPop(stack);
//
//			switch (ar[i])
//			{
//			case '+':
//				ListStackPush(stack, x + y);
//				break;
//			case '-':
//				ListStackPush(stack, x - y);
//				break;
//			case '*':
//				ListStackPush(stack, x * y);
//				break;
//			case '/':
//				ListStackPush(stack, x / y);
//				break;
//			}
//		}
//	}
//	printf("结果为：%d", ListStackTop(stack));
//	return 0;
//}
//
//
//////判断栈空
////bool ListStackEmpty(ListStack* pst)
////{
////	return *pst == NULL;
////}
//
////初始化栈
//void ListStackInit(ListStack* pst)
//{
//	*pst = NULL;
//}
//
////取栈顶元素
//DataType ListStackTop(ListStack* pst)
//{
//	assert(*pst != NULL);
//	return (*pst)->data;
//}
//
////压栈
//void ListStackPush(ListStack* pst, DataType x)
//{
//	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
//	assert(node != NULL);
//	node->data = x;
//
//	node->next = *pst;
//	*pst = node;
//}
//
////出栈
//void ListStackPop(ListStack* pst)
//{
//	StackNode* p = *pst;
//	*pst = p->next;
//	free(p);
//}

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























//typedef struct SListNode//创建节点
//{
//	DataType data;
//	struct SListNode* next;
//}SListNode;
//
//SListNode* CreateSList()
//{
//	SListNode* first = (SListNode*)malloc(sizeof(SListNode));
//	SListNode* last = first;
//	SListNode* new = NULL;
//	int i = 0;
//	int size = 0;
//	printf("数据个数:>");
//	scanf("%d", &size);
//	printf("请输入数据 :>");
//	for (i = 0; i < size; i++)
//	{
//		new = (SListNode*)malloc(sizeof(SListNode));
//		scanf("%d", &new->data);
//		last->next = new;
//		last = new;
//		last->next = NULL;
//	}
//	return first;
//}
//
//void ShowList(SListNode* list1)
//{
//	SListNode* tem = list1->next;
//	while (tem != NULL) {
//		printf("%d  ", tem->data);
//		tem = tem->next;
//	}
//	printf("\n");
//}
//
//SListNode* GetMergeList(SListNode* list1, SListNode* list2)
//{
//	SListNode* tem = list1->next;
//	while (1)
//	{
//		if (tem->next == NULL)
//		{
//			tem->next = list2->next;
//			break;
//		}
//		tem = tem->next;
//	}
//	return list1;
//}
//
//void Reverse(SListNode* list)
//{
//	SListNode* tem = list->next;
//	SListNode* new;
//	list->next = NULL;
//	while (tem != NULL)
//	{
//		new = tem;
//		tem = tem->next;
//		new->next = list->next;
//		list->next = new;
//	}
//}
//
//
//int main()
//{
//	//创建链表1
//	printf("创建链表1:\n");
//	SListNode* list1 = CreateSList();
//	printf("链表1:\n");
//	ShowList(list1);//显示链表
//	printf("\n");
//	//创建链表2
//	printf("创建链表2\n");
//	SListNode* list2 = CreateSList();
//	printf("链表2:\n");
//	ShowList(list2);
//	printf("\n");
//	//合并链表
//	printf("合并链表:");
//	SListNode* list = GetMergeList(list1, list2);
//	ShowList(list);
//	//逆置链表
//	printf("逆置链表:\n");
//	Reverse(list);
//	ShowList(list);
//	return 0;
//}