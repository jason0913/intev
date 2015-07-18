#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 循环队列的操作

#define MAXSIZE 50
typedef int Datatype;
typedef struct
{
	Datatype data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

SqQueue * Init_SqQueue( )
{
	SqQueue *sq;
	sq = (SqQueue*) malloc(sizeof(SqQueue));
	if (sq == NULL)
	{
		printf("malloc SqQueue fail\n");
		return NULL;
	}
	sq->front = 0;
	sq->rear = 0;
	return sq;
}

int Queue_length(SqQueue *sq)
{
	if (sq == NULL)
	{
		return 0;
	}
	return ((sq->rear - sq->front + MAXSIZE) % MAXSIZE);
}

int Enqueue(SqQueue *sq, Datatype e)
{
	if (sq->front == (sq->rear + 1) % MAXSIZE)
	{
		printf("queue full\n");
	}
	sq->data[sq->rear] = e;
	sq->rear = (sq->rear + 1) % MAXSIZE;
	return 0;
}

int Dequeue(SqQueue *sq,Datatype *e)
{
	if (sq->front == sq->rear)
	{
		printf("Empty queue\n");
	}
	*e = sq->data[sq->front];
	sq->front = (sq->front + 1) % MAXSIZE;
	return 0;
}

int Empty_queue(SqQueue *sq)
{
	if (sq->front == sq->rear)
	{
		return 1;
	}
	else
	{
		return 0;	
	}
}
void Destroy(SqQueue *sq)
{
	if (sq != NULL)
	{
		free(sq);
	} 
}

int main(int argc, char* argv[]) 
{	
	int len;
	int value;
	SqQueue * sq = Init_SqQueue();
	if (Empty_queue(sq))
	{
		printf("Initial empty queue\n");		
	} 
	len = Queue_length(sq);
	printf("before enqueue length = %d \n",len);
	Enqueue(sq,1);
	Enqueue(sq,2);
	Enqueue(sq,3);
	len = Queue_length(sq);
	printf("after enqueue length = %d \n",len);
	Dequeue(sq,&value);	
	len = Queue_length(sq);
	printf("dequeue length = %d ,value = %d\n",len,value);
	Destroy(sq);
	return 0;
}

