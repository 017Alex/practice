#pragma once
#include"common.h"

#define P 13

typedef struct HashNode
{
	DataType data;
	struct HashNode* link;
}HashNode;

typedef HashNode* HashTable[P];

////////////////////////////////////////////////////////////////////////
void HashTableInit(HashTable pht);//³õÊ¼»¯¹þÏ£±í
bool HashTableInsert(HashTable pht, DataType x);
int Hash(int x);

int Hash(int x)
{
	return x = x % P;
}

void HashTableInit(HashTable pht)
{
	for (int i = 0; i < P; ++i)
	{
		pht[i] = NULL;
	}
}

bool HashTableInsert(HashTable pht, DataType x)
{
	int index = Hash(x);
	HashNode* s = (HashNode*)malloc(sizeof(HashNode));
	if (s == NULL)
		return false;
	s->data = x;
	s->link = pht[index];
	pht[index] = s;
	return true;
}