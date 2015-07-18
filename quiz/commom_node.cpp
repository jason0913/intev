/*
find first common node in two linklist
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct listnode
{
	int value;
	struct listnode *next;
}ListNode;

// the arg of head must be point to point
void AddTail(ListNode **head,int num)
{
	ListNode *ptr;
	ptr = (ListNode*)malloc(sizeof(ListNode));
	ptr->value =num;
	ptr->next = NULL;
	if (NULL ==*head)
	{
		*head = ptr;
	}
	else
	{
		ListNode *p;
		p = *head;
		while(NULL !=p->next)
		{
			p = p->next;
		}

		p->next = ptr;
		// p = ptr;
	}
}
void Print(ListNode *ptr)
{
	// ListNode *ptr = head;
	while(NULL !=ptr)
	{
		cout<<ptr->value <<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}
ListNode *FirstCommonNode(ListNode *phead1,ListNode *phead2)
{
	ListNode *ptr1 = phead1;
	ListNode *ptr2 = phead2;

	while(NULL != ptr1)
	{
		ptr2 = phead2;
		while(NULL != ptr2)
		{
			if (ptr1->value == ptr2->value)
			{
				cout<<ptr2->value<<" ";
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

int main(int argc, char const *argv[])
{
	int i;
	ListNode *head1=NULL;
	for (int i = 0; i < 10; ++i)
	{
		AddTail(&head1,i);
	}
	cout<<"head1------"<<endl;
	Print(head1);
	ListNode *head2=NULL;
	for (int i = 5; i < 10; ++i)
	{
		AddTail(&head2,i);
	}
	cout<<"head2------"<<endl;
	Print(head2);
	cout<<"common------"<<endl;
	FirstCommonNode(head1,head2);
	return 0;
}