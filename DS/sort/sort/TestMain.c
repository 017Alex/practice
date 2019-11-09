#include"sort.h"

int main()
{
	int ar[] = { 5, 7, 9, 3, 0, 2, 4, 9, 8 };
	int n = sizeof(ar) / sizeof(int);
	TwoWayInsertSort();
	PrintArray(ar, 0, n - 1);
	return 0;
}