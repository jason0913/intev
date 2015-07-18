#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链栈的操作

typedef int Datatype;
typedef struct	StackNode
{
	Datatype data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

LinkStack * Init_stack()
{
	LinkStack *lst = (LinkStack *) malloc(sizeof(LinkStack));
	if (lst == NULL)
	{
		printf("Initial stack fail\n");
		return NULL;
	}
	lst->count = 0;
	lst->top = NULL;
	return lst;
}

int Push(LinkStack *lst,Datatype e)
{
	LinkStackPtr node = (LinkStackPtr) malloc(sizeof(StackNode));
	if (node == NULL)
	{
		printf("malloc stack node fail\n");
		return -1;
	}
	node->data = e;
	node->next = lst->top;
	lst->top = node;
	lst->count ++;
	return 0;
}

int Pop(LinkStack *lst,Datatype *e)
{	
	LinkStackPtr p;
	if (lst->count == 0)
	{
		printf("Empty stack\n");
		return 0;
	}
	*e = lst->top->data;
	p = lst->top;
	lst->top = lst->top->next;
	if(p != NULL)
		free(p);
	lst->count--;
	return 0;
}

int Stack_length(LinkStack *lst)
{
	if (lst->count == 0)
	{
		return 0;
	} 
	else
	{
		return lst->count;
	}
}

int Empty_stack(LinkStack *lst)
{
	if (lst->count == 0)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

void Destroy(LinkStack *lst)
{
	if (lst != NULL)
	{
		free(lst);
	}
}
int main(int argc, char* argv[]) 
{
	int len;
	int value;
	LinkStack *lst = Init_stack();
	if (Empty_stack(lst) == 1)
	{
		printf("Initial empty stack\n");
	}
	len = Stack_length(lst);
	printf("befor Push stack length = %d\n",len);
	Push(lst,1);
	Push(lst,2);
	Push(lst,3);
	Pop(lst,&value);
	len = Stack_length(lst);
	printf("after Push stack length = %d\n",len);
	Destroy(lst);
	return 0;
}
