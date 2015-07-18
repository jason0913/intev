#include "ds.h"

typedef int Datatype;

typedef struct node
{
	Datatype data;
	struct node *next;
}Node;

typedef struct linkqueue
{
	Node *first;
	Node *rear;
}Linkqueue;

Linkqueue * Enqueue(Linkqueue *HQ,int x)
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

	if (NULL ==HQ->rear)
	{
		HQ->first = s;
		HQ->rear =s;
	}
	else
	{
		HQ->rear->next = s;
		HQ->rear = s;
	}
	return HQ;
}

Linkqueue *Outqueue(Linkqueue *HQ)
{
	if (NULL == HQ->first)
	{
		printf("empty queue\n");
		exit(-1);
	}
	Node *p;
	p = HQ->first;
	if (HQ->first == HQ->rear)
	{
		HQ->first = HQ->rear = NULL;
	}
	else
	{
		HQ->first = p->next;
		free(p);
	}
	return HQ;
}

int Length(Linkqueue *HQ)
{
	int n=0;
	Node *p;
	p = HQ->first;
	while(p)
	{
		p = p->next;
		n++;
	}
	return n;
}

void Print_Queue(Linkqueue *HQ)
{
	Node *p;
	p = HQ->first;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	Linkqueue *HQ;
	HQ = (Linkqueue*)malloc(sizeof(Linkqueue));
	if (NULL == HQ)
	{
		perror("malloc HQ error");
		exit(-1);
	}
	HQ = Enqueue(HQ,1);
	HQ = Enqueue(HQ,2);
	HQ = Enqueue(HQ,3);
	Print_Queue(HQ);
	printf("Length = %d\n", Length(HQ));
	printf("Outqueue:\n");
	HQ = Outqueue(HQ);
	Print_Queue(HQ);
	return 0;
}