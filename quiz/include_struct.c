#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 结构体中的结构体初始化
#define LEN 10
typedef struct 
{
	int elem;
	int* addr;
}HashNode;
typedef struct
{
	HashNode* ht;
	int count;
}HashTable;

typedef struct 
{
	int elem;
	int addr[LEN];
}HashNode2;

typedef struct
{
	HashNode2 ht;
	int count;
}HashTable2;

int main(int argc, char* argv[]) 
{
	HashTable *H = (HashTable *)malloc(sizeof(HashTable));
	if (H == NULL)
	{
		printf("malloc HashTable fail\n");
	}
	H->count = 0;
	//(&H->ht)->elem = 1;
	//(&(H->ht))->addr = (int*)malloc(LEN *sizeof(int));
	H->ht = (HashNode*)malloc(sizeof(HashNode));
	H->ht->elem = 1;
	H->ht->addr = NULL;
	
	HashTable2 *H2 = (HashTable2 *)malloc(sizeof(HashTable2));
	if (H2 == NULL)
	{
		printf("malloc HashTable fail\n");
	}
	H2->count = 0;
	(&H2->ht)->elem = 1;
	(&(H2->ht))->addr[0] = 1;
	
	HashTable H3;
	H3.count = 0;
	H3.ht = (HashNode*)malloc(sizeof(HashNode));  // 结构体有结构体，而且使指针类型的结构体，那么这个指针结构体要malloc初始化,
	H3.ht->addr = NULL;
	H3.ht->elem = 0;
	return 0;
}