#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>

using namespace std;

struct ListNode
{
	int value;
	struct ListNode *next;
};

void PrintListReverse(struct ListNode *phead)
{
	stack <struct ListNode*> pstack;
	struct ListNode *p =phead;

	while(NULL != p)
	{
		pstack.push(p);
		p = p->next;
	}
	while(! pstack.empty())
	{
		p = pstack.top();
		cout << p->value<<endl;
		pstack.pop();
	}
}
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

int main(int argc, char const *argv[])
{
	struct ListNode *head=NULL;
	for (int i = 0; i < 10; ++i)
	{
		AddToTail(&head,i);
	}
	PrintListReverse(head);
	return 0;
}