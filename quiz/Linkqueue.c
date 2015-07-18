#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链式队列的操作

typedef int Datatype;
typedef struct Qnode
{
	Datatype data;
	struct Qnode *next;
}Qnode,*Qnode_ptr;

typedef struct
{
	Qnode_ptr front;
	Qnode_ptr rear;
}LinkQueue;

LinkQueue * Init_queue( )
{
	LinkQueue *lq = (LinkQueue *) malloc(sizeof (LinkQueue));
	if (lq == NULL)
	{
		printf("malloc LinkQueue fail\n");
		return NULL;
	}
	lq->front = NULL;
	lq->rear = NULL;
	return lq;
}

int Enqueue(LinkQueue *lq,Datatype e)
{
	Qnode_ptr qnode = (Qnode_ptr) malloc(sizeof(Qnode));
	if (qnode == NULL)
	{
		printf("malloc qnode fail\n");
		return -1;
	}
	qnode->data = e;
	qnode->next = NULL;
	lq->rear->next = qnode;
	lq->rear = qnode;
	return 0;	
}

int Dequeue(LinkQueue *lq, Datatype *e)
{
	if (lq->front == NULL && lq->rear == NULL)
	{
	  printf("Empty queue\n");
	  return -1;
	}
	Qnode * tmp = lq->front->next;
	*e = tmp->data;	
	lq->front->next = tmp->next;
	if (tmp == lq->rear)
	{
		lq->front = lq->rear;
	}
	if (tmp != NULL)
	{
		free(tmp);
	}
	return 0;
}
int Empty_queue(LinkQueue *lq)
{
	if(lq->front == lq->rear)
		return 1;
	else
		return 0;
}
void Destroy(LinkQueue *lq)
{
	if (lq != NULL)
	{
		free(lq);
	} 
}

int main(int argc, char* argv[]) 
{
	int value;
	LinkQueue *lq = Init_queue();
	if (Empty_queue(lq) == 1)
	{
		printf("Initial Empty queue\n");
	}
	Enqueue(lq,1);
	Enqueue(lq,2);
	Enqueue(lq,3);
	Dequeue(lq,&value);
	printf("Dequeue a value = %d\n",value);
	Destroy(lq);
	return 0;
}