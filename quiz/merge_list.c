/*
merge to linklist into one
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
	printf("\n");
}

struct ListNode *MergeList(struct ListNode *head1,struct ListNode *head2)
{
	if (NULL == head1 && NULL == head2)
	{
		return NULL;
	}
	if (NULL == head1 || NULL == head2)
	{
		return ((NULL != head1)? head1:head2);
	}
	struct ListNode *head3=NULL;
	while((NULL != head1) && (NULL != head2))
	{
		if (head1->value <= head2->value)
		{
			AddToTail(&head3,head1->value);
			head1 = head1->next;
		}
		else
		{
			AddToTail(&head3,head2->value);
			head2 = head2->next;
		}
	}
	if(NULL != head1)
	{
		head3->next = head1;
	}
	if(NULL != head2)
	{
		head3->next = head2;
	}
	return head3;
}

struct ListNode *MergeList2(struct ListNode *head1,struct ListNode *head2)
{
	if (NULL == head1)
	{
		return head2;
	}
	else if (NULL == head2)
	{
		return head1;
	}
	struct ListNode *head3=NULL;
	if (head1->value <head2->value)
	{
		head3 = head1;
		head3->next = MergeList2(head1->next,head2);
	}
	else
	{
		head3 = head2;
		head3->next = MergeList2(head1,head2->next);
	}
	return(head3);
}
int main(int argc, char const *argv[])
{
	struct ListNode *head1=NULL;
	struct ListNode *head2=NULL;
	struct ListNode *head3=NULL;
	for (int i = 0; i < 10; ++i)
	{
		if (0 != (i & 1))
		{
			AddToTail(&head1,i);
		}
		else
			AddToTail(&head2,i);
	}
	Print(head1);
	printf("-------\n");
	Print(head2);
	printf("MergeList-------\n");
	head3= MergeList(head1,head2);
	Print(head3);
	printf("MergeList2-------\n");
	head3= MergeList2(head1,head2);
	Print(head3);
	return 0;
}