#include <stdio.h>
#include <stdlib.h>

// 逆序输出单链表
typedef struct listnode
{
	int value;
	struct listnode *next;
}ListNode;

int main()
{
	ListNode *head;
	ListNode *tail;
	ListNode *tmp;
	ListNode *cur;
	ListNode *prev;
	int c;
	
	head = (ListNode *) malloc(sizeof(ListNode));
	if(head == NULL)
	{
		printf("malloc error\n");
		return -1;
	}
	head->value = 0;
	head->next = NULL;
	tail = head;
	printf("Input listnode:\n");
	while((c = getchar()) != '\n')
	{
		if(c != ' ')
		{
			tmp = (ListNode *)malloc(sizeof(ListNode));
			if(tmp == NULL)
			{
				printf("malloc error\n");
				return -1;
			}
			tmp->value = c;
			tmp->next = NULL;
			tail->next = tmp;
			tail = tail->next;
		}
	}
	printf("Init ListNode:\n");
	tail = head->next;
	while(tail != NULL)
	{
		printf("%c ",tail->value);
		tail = tail->next;
	}
	tail = head->next;
	head = head->next;
	prev = NULL;
	while(head)
	{
		cur = head;
		head = head->next;
		cur->next = prev;
		prev =	cur;

	}
	printf("Reverse List:\n");
	while(cur)
	{
	    printf("%c ",cur->value);
	    cur = cur->next;
	}
	system("pause");
	return 0;
}