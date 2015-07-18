#include "ds.h"

// squeue list operator

#define MAXSIZE 100

typedef int Dataype;

typedef struct
{
	Dataype data[MAXSIZE];
	int length;
}Sqlist;

// init a sqlist
void Init_sqlist(Sqlist **list)
{
	*list = (Sqlist *)malloc(sizeof(Sqlist));
	if (NULL == *list)
	{
		perror("Init_sqlist error");
		exit(-1);
	}
	(*list)->length = 0;
}
// append element to sqlist
void Append_sqlist(Sqlist *list,Dataype x)
{
	printf("length %d\n", list->length);
	if (MAXSIZE !=list->length)
	{
		list->data[list->length] = x;
		list->length++;
	}
}
// insert element into sqlist at index i
void Insert_sqlist(Sqlist *list,int i,Dataype x)
{
	int j;
	if (MAXSIZE == list->length)
	{
		printf("Sqlist full\n");
		exit(-1);
	}
	if (i <0 || i > list->length)
	{
		printf("insert index error\n");
		exit(-1);
	}
	for (j = list->length-1; j >= i-1; j--)
	{
		list->data[j+1] = list->data[j];
	}
	list->data[i-1] = x;
	list->length = list->length +1;
}
// delete element which index i
void Delete_sqlist(Sqlist *list,int i)
{
	int j;
	if (i<0 || i>list->length)
	{
		printf("Delete_sqlist index erro\n");
		exit(-1);
	}
	if (0==list->length)
	{
		printf("empty sqlist\n");
		exit(-1);
	}
	for (j = i-1; j < list->length; ++j)
	{
		list->data[j] = list->data[j+1];
	}
}
// find element which x
int Locate_sqlist(Sqlist *list,Dataype x)
{
	int i;
	for (i = 0; i < list->length; ++i)
	{
		if (x == list->data[i])
		{
			return i;
		}
	}
	return -1;
}
//  print sqlist
void Print_sqlist(Sqlist *list)
{
	int i;
	if (0 != list->length)
	{
		for (i = 0; i < list->length; ++i)
		{
			printf("%d ", list->data[i]);
		}
		printf("\n");
	}
	else
		printf("empty\n");
}

int main(int argc, char const *argv[])
{
	int  i;
	// in case dangling point
	Sqlist *list = NULL;
	printf("list %x\n", list);
	Init_sqlist(&list);
	printf("list %x x\n", list);
	printf("list %x x\n", *&list);
	for (i = 0; i < 10; ++i)
	{
		Append_sqlist(list,i);
	}
	Insert_sqlist(list,5,10);
	Print_sqlist(list);
	return 0;
}
