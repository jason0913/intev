#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int value;
	struct ListNode *next;
};

void AddToTail(struct ListNode ** PHead,int value)
{
	struct ListNode *PNew =(struct ListNode *)malloc(sizeof(struct ListNode));
	PNew->value = value;
	PNew->next = NULL;

	if (NULL == *PHead)
	{
		*PHead = PNew;
	}
	else
	{
		struct ListNode *pNode = *PHead;
		while(NULL != pNode->next)
		{
			pNode = pNode->next;
		}
		pNode->next = PNew;
	}
}
void Print(struct ListNode *head)
{
	while(NULL != head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
}
int main(int argc, char const *argv[])
{
	struct ListNode *head=NULL;
	for (int i = 0; i < 10; ++i)
	{
		AddToTail(&head,i);
	}
	Print(head);
	return 0;
}