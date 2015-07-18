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
int GetLength(ListNode *head)
{
	int length =0;
	if (NULL == head)
	{
		return 0;
	}
	while(head)
	{
		length++;
		head = head->next;
	}
	return length;
}
ListNode *FirstCommonNode(ListNode *phead1,ListNode *phead2)
{
	ListNode *ptr1 = phead1;
	ListNode *ptr2 = phead2;

	int len1 = GetLength(phead1);
	int len2 = GetLength(phead2);
	cout<<"len1 "<<len1<<" len2:"<<len2<<endl;

	while(NULL != ptr1->next)
	{
		ptr1 = ptr1->next;
	}
	while(NULL != ptr2->next)
	{
		ptr2 = ptr2->next;
	}
	if ((ptr2->value == ptr1->value) && (ptr1->next == ptr2->next))
	{
		cout<<"has common node"<<endl;
	}
	else
		cout<<"no common node"<<endl;

	ptr1 = phead1;
	ptr2 = phead2;
	int kstep =0;
	if (len1 >len2)
	{
		while(NULL != ptr1)
		{
			if (kstep > len1-len2-1)
			{
				break;
			}
			kstep++;
			ptr1 = ptr1->next;
		}
	}
	else
	{
		while(NULL != ptr2)
		{
			if (kstep > len2-len1-1)
			{
				break;
			}
			kstep++;
			ptr2 = ptr2->next;
		}
	}
	while((NULL != ptr1) && (NULL != ptr2))
	{
		// if ((ptr1->value == ptr2->value) && (ptr1->next == ptr2->next))
		if ((ptr1->next == ptr2->next))
		{
			cout<<"common node:"<<ptr1->value<<endl;
		}
		ptr1= ptr1->next;
		ptr2= ptr2->next;
	}
}

int main(int argc, char const *argv[])
{
	int i;
	ListNode *head1=NULL;
	for (int i = 1; i < 4; ++i)
	{
		AddTail(&head1,i);
	}
	cout<<"head1------"<<endl;
	Print(head1);
	ListNode *head2=NULL;
	for (int i = 5; i < 8; ++i)
	{
		AddTail(&head2,i);
	}
	// link list1 to the tail of list2
	ListNode *tmp = head2;
	while(NULL != tmp->next)
	{
		tmp= tmp->next;
	}
	tmp->next = head1;
	cout<<"head2------"<<endl;
	Print(head2);
	cout<<"common------"<<endl;
	FirstCommonNode(head1,head2);
	return 0;
}