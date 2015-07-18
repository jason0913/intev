#include <stdio.h>
#include <stdlib.h>

// 求俩个集合的差集
typedef struct node
{
	int data;
	struct node *next;
}Node;

int main()
{	
	Node *A,*B,*C,*tailA,*tailB,*tailC,*temp;
	int c;
	A = (Node *)malloc(sizeof(Node));
	B = (Node *)malloc(sizeof(Node));
	C = (Node *)malloc(sizeof(Node));
	if( A == NULL || B == NULL ||C == NULL)
	{
		printf("malloc Node error\n");
		return -1;
	}
	A->data = 0;
	A->next = NULL;
	B->data = 0;
	B->next = NULL;
	C->data = 0;
	C->next = NULL;
	tailA = A;
	tailB = B;
	tailC = C;
	printf("Init set A:\n");
	while((c = getchar()) != '\n')
	{
		if(c != ' ')
		{
			temp = (Node *)malloc(sizeof(Node));
			temp->data = c;
			temp->next =NULL;
			tailA->next = temp;
			tailA = tailA->next;
		}		
	}
	printf("set A is:\n");
	tailA = A->next;
	while(tailA != NULL)
	{
		printf("%c ",tailA->data);
		tailA = tailA->next;
	}
	printf("Init set B:\n");
	while((c = getchar()) != '\n')
    {
		if(c != ' ')
		{
			temp = (Node *)malloc(sizeof(Node));
			temp->data = c;
			temp->next =NULL;
			tailB->next = temp;
			tailB = tailB->next;
		}    	
    }
	printf("set B is:\n");
	tailB = B->next;
	while(tailB != NULL)
	{
		printf("%c ",tailB->data);
		tailB = tailB->next;
	}
	tailA = A->next;
	
	while(tailA != NULL)
	{
		tailB = B->next;
		while( tailB != NULL)
		{
			if(tailB->data == tailA->data)
			{
				break;
			}
			else
				tailB = tailB->next;
		}
		if(tailB == NULL)
		{
			temp = (Node *)malloc(sizeof(Node));
			temp->data = tailA->data;
			temp->next =NULL;
			tailC->next = temp;
			tailC = tailC->next;
		}
		tailA = tailA->next;
	}
	printf("diffent set is:\n");
	tailC = C->next;
	while(tailC != NULL)
	{
		printf("%c ",tailC->data);
		tailC = tailC->next;
	}
	return 0;
}   