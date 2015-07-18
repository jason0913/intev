#include "alg.h"

#define SIZE 50

typedef struct 
{
	int key;
	int startaddr;
}IndexItem;

typedef struct
{
	IndexItem elem[SIZE];
	int length;
}IndexTable;

typedef struct 
{
	int arr[100];
	int length;
}SSTable;

int BlockSearch(SSTable *SST,IndexTable *ITB,int key)
{
	int low,high,mid;
	int i,l,h;
	int p; //index location
	int s,t; // s,t store index start and end

	low = 0;
	high = ITB->length;
	while(low < high)
	{
		mid = (low + high) /2;
		if (key == ITB->elem[mid].key)
		{
			i = mid;
			break;
		}
		else if (key < ITB->elem[mid].key)
		{
			high = mid-1;
		}
		else
			low = mid +1;
	}
	if (low > high)
	{
		i = low;
	}
	if (i == ITB->length)
	{
		return 0;
	}
	l = ITB->elem[i].startaddr;
	if (i == ITB->length -1)
	{
		h = SST->length;
	}
	else
		h = ITB->elem[i+1].startaddr -1;
	while(l <= h)
	{
		if (key == SST->arr[l])
		{
			break;
		}
		else
			l++;
		if (l <= h)
		{
			return 1; // serach success
		}
		else
			return 0; // search failed
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}