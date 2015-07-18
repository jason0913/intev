#include <stdio.h>
#include <stdlib.h>

// 排序单链表
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
	ListNode *post;
	int c;
	int tmpval;
	
	head = (ListNode *) malloc(sizeof(ListNode));
	if(head == NULL)
	{
		printf("malloc error\n");
		return -1;
	}
	head->value = 0;
	head->next = NULL;
	tail = head;
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
	while(tail != NULL)
	{
		post = tail->next;
		while(post != NULL)
		{
			if (tail->value > post->value)
			{	
				
				tmpval = tail->value;
				tail->value = post->value;
				post->value = tmpval;
			} 
			post = post->next;
		}
		tail = tail->next;
	}
	printf("Sort ListNode:\n");
	tail = head->next;
	while(tail != NULL)
	{
		printf("%c ",tail->value);
		tail = tail->next;
	}
	return 0;
}