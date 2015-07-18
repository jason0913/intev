#include "ds.h"

typedef int Datatype;

typedef struct node
{
	Datatype data;
	struct node *next;
}Node;

typedef struct stk
{
	Node *top;
}Stack;

Stack * Push(Stack *HQ,int x)
{
	Node *s;
	s = (Node*)malloc(sizeof(Node));
	if (NULL ==s)
	{
		perror("malloc error");
		exit(-1);
	}
	s->data =x;
	s->next = NULL;

	if (NULL == HQ->top)
	{
		HQ->top = s;
	}
	else
	{
		s->next = HQ->top;
		HQ->top = s;
	}
	
	return HQ;
}

Stack *Pop(Stack *HQ)
{
	if (NULL == HQ->top)
	{
		printf("empty stack\n");
		exit(-1);
	}
	Node *p;
	p = HQ->top;
	if (NULL == HQ->top->next)
	{
		HQ->top = NULL;
		free(p);
	}
	else
	{
		HQ->top = HQ->top->next;
		free(p);
	}
	return HQ;
}

int Length(Stack *HQ)
{
	int n=0;
	Node *p;
	p = HQ->top;
	while(p)
	{
		p = p->next;
		n++;
	}
	return n;
}

void Print_Stack(Stack *HQ)
{
	Node *p;
	p = HQ->top;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	Stack *HQ;
	HQ = (Stack*)malloc(sizeof(Stack));
	if (NULL == HQ)
	{
		perror("malloc HQ error");
		exit(-1);
	}
	HQ = Push(HQ,1);
	// Print_Stack(HQ);
	HQ = Push(HQ,2);
	// Print_Stack(HQ);
	HQ = Push(HQ,3);
	Print_Stack(HQ);
	printf("Length = %d\n", Length(HQ));
	printf("Pop:\n");
	HQ = Pop(HQ);
	Print_Stack(HQ);
	return 0;
}