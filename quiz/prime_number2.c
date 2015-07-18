#include <stdio.h>
#include <stdlib.h>

struct prime_number_node
{
	int prime_number;
	struct prime_number_node* next;
};
typedef struct prime_number_node PND;

int count_prime_number()
{
	int half,i,j;
	int remainder;
	int result = 0;
	int start,end;
	printf("Input start number (>=3):");
	scanf("%d",&start);
	printf("Input end number:");
	scanf("%d",&end);
	PND * head = (PND*) malloc(sizeof(PND));
	PND * iter = (PND*) malloc(sizeof(PND));
	PND * tail = (PND*) malloc(sizeof(PND));
	if(head == NULL || tail == NULL || iter == NULL)
	{
		printf("malloc head or tail or iter error\n");
		return -1;
	}
	head->prime_number = 2;
	head->next = NULL;
	tail = head;
	iter = head;
	for(i = start; i <= end ; i++)
	{
		half = i / 2;
		j = 2;
		remainder = 0;
		while(j <= half)
		{
			remainder = i % j;
			if(remainder == 0)
				break;
			else
				j ++;
		}
		if(remainder == 1)
		{
			PND *temp = (PND*) malloc(sizeof(PND));
			if(temp == NULL)
			{
				printf("malloc head or tail error\n");
				return -1;
			}
			temp->prime_number = i;
			temp->next = NULL;
			tail->next = temp;
			tail = tail->next;
		}
	}
	while(iter != NULL)
	{
		result++;
		printf("%d ",iter->prime_number);
		iter = iter->next;
	}
}

int main()
{
	count_prime_number();
	return 0;
}