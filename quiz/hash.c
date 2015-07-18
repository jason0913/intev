#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAIL 0
#define HASHSIZE 12
#define NULLKEY -32768

// 哈希函数的操作
typedef struct 
{
	int *elem;
	int count;
}HashTable;

int m = 0;

HashTable* Init_hashtable()
{
	HashTable *H;
	int i ;
	m = HASHSIZE;
	H = (HashTable *)malloc(sizeof(HashTable));
	if (H == NULL)
	{
		printf("malloc hashtable fail\n");
		return NULL;
	}
	H->count = m;
	H->elem = (int *)malloc(m * sizeof(int));
	for ( i= 0; i < m; ++i) 
	{
		H->elem[i] = NULLKEY;
	}
	return H;
}
void Show_hashtable(HashTable *H)
{	
	int i;
	for ( i= 0; i < HASHSIZE; ++i) 
	{	
		if(H->elem[i] == NULLKEY)
			printf("NULLKEY ");
		else
			printf("%d ",H->elem[i]);
	}
	printf("\n");
}
int Hash(int key)
{
	return key % HASHSIZE;
}

void InsertHash(HashTable *H, int key)
{
	int addr = Hash(key);
	
	while(H->elem[addr] != NULLKEY)
	{	
		printf("Conflict, Detective next...\n");
		addr = (addr + 1) % HASHSIZE;
	}
	H->elem[addr] = key;
	printf("InsertHash H key = %d\n",key);
}

int SearchHash(HashTable *H, int key, int *addr)
{
	*addr = Hash(key);
	while(H->elem[*addr] != key)
	{
		*addr = (*addr +1 ) % HASHSIZE;
		if (H->elem[*addr] == NULLKEY || *addr == Hash(key))
		{	
			printf("Not find key: %d in HashTable\n",key);
			return FAIL;
		} 
	}
	printf("SearchHash key = %d\n",key);
	return SUCCESS;
}

int main(int argc, char* argv[]) 
{	
	HashTable *H;
	int addr;
	H = Init_hashtable(H);
	if (H != 0)
	{
		printf("Initial a HashTable:\n");
	}
	Show_hashtable(H);
	InsertHash(H,23);
	InsertHash(H,2);
	InsertHash(H,10);
	Show_hashtable(H);
	SearchHash(H,12,&addr);
	return 0;
}