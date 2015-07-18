#include "ds.h"

#define flag -1

typedef int Datatype;

typedef struct node
{
	Datatype data;
	struct node *next;
}Lnode,*LinkList;

void Creat_linkfront(LinkList L)
{
	Lnode *tmp;
	Datatype x;
	int ch;
	while(1)
	{
		scanf("%d",&x);
		tmp = (LinkList)malloc(sizeof(Lnode));
		if (NULL == tmp)
		{
			perror("malloc Lnode error");
			return;
		}
		tmp->data =x;
		tmp->next = L->next;
		L->next = tmp;
		// scanf("%c",&ch);
		// if use scanf must be char ch
		// in order to end scanf with \n
		ch = getchar();
		if ('\n' ==ch)
		{
			break;
		}
	}
}

void Creat_linkrear(LinkList L)
{
	Lnode *r,*s;
	Datatype x;
	scanf("%d",&x);
	r = L;
	while(x != flag)
	{
		s = (LinkList)malloc(sizeof(Lnode));
		s->data = x;
		s->next = r->next;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
}

Lnode *Get_LinkList(LinkList L,int i)
{
	Lnode *p;
	int j;
	p = L;
	j = 0;
	while(p !=NULL && j <i)
	{
		i++;
		p = p->next;
	}
	return p;
}
Lnode *Locate_LinkList(LinkList L,Datatype x)
{
	Lnode *p;
	p =L->next;
	while(p!= NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}
void Insert_LinkList(LinkList L,int i,Datatype x)
{
	Lnode *p,*s;
	p = Get_LinkList(L,i-1);
	if (NULL == p)
	{
		printf("Postion invalid\n");
		return;
	}
	else
	{
		s = (LinkList)malloc(sizeof(Lnode));
		s->data =x;
		s->next = p->next;
		p->next = s;
	}
}
void Delete_LinkList(LinkList L,int i)
{
	Lnode *p,*q;
	p = Get_LinkList(L,i-1);
	if (NULL == p)
	{
		printf("invalid position\n");
		return;
	}
	else
	{
		if (NULL == p->next)
		{
			printf("p->next == NULL,cannot delete\n");
			return ;
		}
		q = p->next;
		p->next = q->next;
		free(q);
	}
}
int Length_LinkList(LinkList L)
{
	Lnode *p;
	p = L;
	int len=0;
	while(p->next)
	{
		p=p->next;
		len++;
	}
	return len;
}
void Print_list(LinkList L)
{
    LinkList t;
    t = L;
    while(NULL != t)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}
// reverse list by using three point
void Reverse(LinkList L)
{
	Lnode *pre,*p,*r;
	p = L->next;
	r = p->next;

	p->next = NULL;
	while(r)
	{
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;

	}
	// r->next = pre;
	L->next = p;
}
// reverse list similiar to insert list front
void Reverse2(LinkList L)
{
	Lnode *r,*p,*H;
	r = L->next;
	// H = (Lnode *)malloc(sizeof(Lnode));
	L->next = NULL;
	while(r)
	{
		p = r;
		r = r->next;

		p->next = L->next;
		L->next = p;

	}
}
int main(int argc, char const *argv[])
{
	LinkList L;
	L = (LinkList)malloc(sizeof(Lnode));
	if (NULL == L)
	{
		perror("malloc LinkList error");
		exit(1);
	}
	L->next = NULL;
	printf("this operator has default data=0\n");
	Print_list(L);
    printf("Init LinkList dont need end with -1\n");
	Creat_linkfront(L);
    Print_list(L->next);
    printf("Length_LinkList %d\n",Length_LinkList(L));
    printf("Insert_LinkList\n");
    Insert_LinkList(L,3,100);
    Print_list(L->next);
    printf("Reverse LinkList\n");
    Reverse(L);
    Print_list(L->next);

    printf("Reverse2 LinkList\n");
    Reverse2(L);
    Print_list(L->next);
	return 0;
}
