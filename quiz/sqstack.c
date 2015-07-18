#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 顺序栈的操作

#define MAXSIZE 100

typedef int Datetype;	
typedef struct{
	Datetype data[MAXSIZE];
	int top;
}Sqstack;

Sqstack * Init_stack()
{
	Sqstack *st = (Sqstack *)malloc(sizeof(Sqstack));
	if (st == NULL)
	{
		printf("malloc Sqstack error\n");
		return NULL;
	} 
	st->top = -1;
	return st;
}

int Push(Sqstack *st,Datetype e)
{
	if (st->top == MAXSIZE -1)
	{
		printf("stack full\n");
		return -1;
	}
	st->top ++;
	st->data[st->top] = e;
	return 0;
}

int Pop(Sqstack *st,Datetype *e)
{
	if (st->top == -1)
	{
		printf("Empty stack\n");
		return -1;
	}
	*e = st->data[st->top];
	st->top--;
	return 0;
}

int Stack_empty(Sqstack *st)
{
	if (st->top == -1)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

int Stack_length(Sqstack *st)
{
	if (st->top == -1)
	{
		return 0;
	}
	return st->top + 1;  		// 如果return st->top++ ,则是先return st->top，返回之后再加加
}

void Destroy_stack(Sqstack *st)
{
	if (st != NULL)
	{
		free(st);
	}	
}
int main(int argc, char* argv[]) 
{	
	int stlen;
	int value;
	Sqstack *st = Init_stack();
	if (Stack_empty(st) == 1)
	{
		printf("Initial a empty stack\n");
	} 
	stlen = Stack_length(st);
	printf("before push stack length = %d\n",stlen);
	Push(st,1);
	Push(st,2);
	Push(st,3);
	stlen = Stack_length(st);
	printf("after push stack length = %d\n",stlen);
	Pop(st,&value);
	printf("Pop value = %d\n",value);
	stlen = Stack_length(st);
	printf("after pop stack length = %d\n",stlen);
	Pop(st,&value);
	printf("Pop value = %d\n",value);
	stlen = Stack_length(st);
	printf("after pop stack length = %d\n",stlen);
	Destroy_stack(st);
	return 0;
}