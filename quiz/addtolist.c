/*
Reverse Print the Linklist
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int value;
	struct ListNode *next;
};

void AddToTail(struct ListNode ** PHead,int value)
{
	struct ListNode *pNew = (struct ListNode*)malloc(sizeof(struct ListNode));
	pNew->value = value;
	pNew->next = NULL;

	if (NULL == *PHead)
	{
		*PHead = pNew;
	}
	else
	{
		struct ListNode *pNode = *PHead;
		while(NULL != pNode->next)
		{
			pNode = pNode->next;
		}
		pNode->next = pNew;
	}
}

void Print(struct ListNode *head)
{
	while(NULL != head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void ReversePrint(struct ListNode *head)
{
	if(NULL != head)
	{
		/*if (NULL != head->next)
		{}*/
		ReversePrint(head->next);
	}
	else
		return;
	printf("%d ",head->value);
}

int main(int argc, char const *argv[])
{
	struct ListNode *head =NULL;
	int i;
	for (i = 0; i < 10; ++i)
	{
		AddToTail(&head,i);
	}

	Print(head);
	ReversePrint(head);
	return 0;
}