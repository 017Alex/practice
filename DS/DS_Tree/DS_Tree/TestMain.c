#include"bintree.h"

int main()
{
	//"ABC##DE##F##G#H##";
	//"ABC##D#F##GE##H##";
	BinTree bt;
	BinTreeInit(&bt);
	BinTreeCreate(&bt);

	printf("VLR   :");
	PreOrder(&bt);
	printf("\n");

	printf("\n");
	printf("LVR   :");
	InOrder(&bt);
	printf("\n");
	
	printf("\n");
	printf("LRV   :");
	PostOrder(&bt);
	printf("\n");
	
	printf("\n");
	printf("Size = %d\n", Size(&bt));
	printf("Hegith = %d\n", Height(&bt));
	BinTreeNode* p;
	p = Parent(&bt, 'H');
	printf("parent :%c", p->data);

	return 0;
}

//#include"queue.h"
//void LevelOrder(BinTree* t)
//{
//	_LevelOrder(t->root);
//}
//void _LevelOrder(BinTreeNode* t)
//{
//	if (t != NULL)
//	{
//		LinkQueue Q;
//		LinkQueueInit(&Q);
//
//		LinkQueueEn(&Q, t);
//		while (!LinkQueueEmpty(&Q))
//		{
//			BinTreeNode* p = LinkQueueFront(&Q);
//			LinkQueueDe(&Q);
//			printf("%c ", p->data);
//			if (p->leftChild != NULL)
//				LinkQueueEn(&Q, p->leftChild);
//			if (p->rightChild != NULL)
//				LinkQueueEn(&Q, p->rightChild);
//		}
//	}
//}