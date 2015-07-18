#include "ds.h"

typedef struct dnode
{
	int data;
	struct dnode *next;
	struct dnode *pre;
}Dnode;

// create a double linklist,without a head node
Dnode *Creat_Dlink()
{
	Dnode *head,*p,*s;
	int x;
	int ch;
	head = (Dnode*)malloc(sizeof(Dnode));
	if (NULL == head)
	{
		perror("malloc Dnode error");
		exit(-1);
	}
	printf("Init double linklist:\n");
	scanf("%d",&x);
	head->data =x;
	head->next = NULL;

	p =head;
	while(1)
	{
		scanf("%d",&x);
		s = (Dnode*)malloc(sizeof(Dnode));
		if (NULL == s)
		{
			perror("malloc Dnode error");
			exit(-1);
		}
		s->data = x;
		s->next = NULL;
		p->next = s;
		s->pre = p;
		p = s;

		ch = getchar();
		if ('\n' == ch)
		{
			break;
		}

	}
	head->pre = NULL;
	return head;
}

void Print_Dlink(Dnode *L)
{
	Dnode *p;
	p = L;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
// delete a node which val =num
Dnode * Delete_Node(Dnode * head, int num)
{
	Dnode *p,*tmp;
	p = head;
	while(p->data != num && p != NULL)
	{
		p = p->next;
	}
	if (NULL == p)
	{
		printf("No node find\n");
		exit(-1);
	}
	if (num == p->data)
	{
		tmp = p;
		if (NULL == p->next)
		{
			p->pre->next = NULL;
			free(tmp);
		}
		// if not elseif ,just if,then last below else will exec
		else if (head == p) 
		{
			head = p->next;
			p->next->pre = NULL;
			free(tmp);
		}
		else
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
			free(tmp);
		}
	}
	return head;
}

Dnode *Insert_linklist(Dnode *head,int pos,int num)
{

	return head;
}
int main(int argc, char const *argv[])
{
	int num;
	Dnode *head;
	head = Creat_Dlink();
	Print_Dlink(head);
	printf("Delete_Node :\n");
	scanf("%d",&num);
	head =Delete_Node(head,num);
	Print_Dlink(head);
	return 0;
}