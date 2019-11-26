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
	printf("Level :");
	LevelOrder(&bt);
	printf("\n");
	
	printf("\n");
	printf("Size = %d\n", Size(&bt));
	printf("Hegith = %d\n", Height(&bt));
	BinTreeNode* p;
	p = Parent(&bt, 'D');
	printf("parent :%c", p->data);

	return 0;
}