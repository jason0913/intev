#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef int Elemtype;

typedef struct BiNode
{
	Elemtype data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTNode * InitRoot()
{
	BiTNode *root;
	root = new BiTNode;
	if (root)
	{
		cout<<"Input root data"<<endl;
		cin>>root->value;
		root->lchild = NULL;
		root->rchild = NULL;

		return root;
	}
	else
		return NULL;
}
BiTNode * FindNode(BiTNode *root,int data)
{
	BiTNode *ptr;
	if (NULL == root)
	{
		return NULL;
	}
	if (data == root->value)
	{
		return root;
	}
	else
	{
		if (ptr = FindNode(root->lchild,data))
		{
			return ptr;
		}
		else if (ptr = FindNode(root->rchild,data))
		{
			return ptr;
		}
		else
			return NULL;
	}
}
void AddTreeNode(BiTNode *root)
{
	BiTNode *pnode,*parent;
	char menusel;
	int pdata;
	
	pnode = new BiTNode;
	if (pnode)
	{
		cout<<"Input node data"<<endl;
		cin>>pnode->value;
		pnode->lchild =NULL;
		pnode->rchild =NULL;

		cout<<"Input parent data"<<endl;
		cin>>pdata;
		parent = FindNode(root,pdata);
		if (NULL == parent)
		{
			cout<<"no parent"<<endl;
			return;
		}
		cout<<"l:lchild,r:rchild"<<endl;
		cin>>menusel;
		switch(menusel)
		{
			case 'l':
				if (NULL != parent->lchild)
				{
					cout<<"lchild has node"<<endl;
					break;
				}
				parent->lchild = pnode;
				cout<<"add "<<pnode->value<<" to lchild "<<parent->value<<endl;
				break;
			case 'r':
				if (NULL != parent->rchild)
				{
					cout<<"rchild has node"<<endl;
					break;
				}
				parent->rchild = pnode;
				cout<<"add "<<pnode->value<<" to rchild"<<parent->value<<endl;
				break;
			default:
				cout<<"invalid choose"<<endl;
				break;
		}
	}
}

void BitreePreOrder(BiTree BT)
{
	BiTree stack[MAX_TREE_SIZE],p;
	int top;

	if (NULL != BT)
	{
		top =1;
		stack[top]= BT;

		while(top >0)
		{
			p =stack[top];
			top--;
			printf("%d \n", p->data);

			if (NULL != p->rchild)
			{
				top++;
				stack[top] = p->rchild;
			}
			if (NULL != p->lchild)
			{
				top++;
				stack[top] = p->lchild;
			}
		}
	}
}

void BitreeInOrder(BiTree BT)
{
	BiTree stack[MAX_TREE_SIZE],p;
	int top =0;
	p = BT;

	do
	{
		while(NULL != p)
		{
			top++;
			stack[top] =p;
			p = p->lchild;
		}
		if (top >0)
		{
			p = stack[top];
			top--;
			printf("%d \n", p->data);
			p = p->rchild;
		}
	} while (NULL != p || top >0);
}

BiTree CreatBiTree()
{
	int ch;
	BiTree BT;
	printf("input data\n");
	scanf("%d",&ch);

	BT = (BiTree)malloc(sizeof(BiNode));
	if (NULL == BT)
	{
		perror("malloc BiTNode error");
		exit(-1);
	}
	BT->data = ch;
	BT->lchild = CreatBiTree(BT->lchild);
	BT->rchild = CreatBiTree(BT->rchild);

	return BT;
}
// search in binary tree
void Search(BiTree BT,Elemtype data)
{
	if (data == BT->data)
	{
		printf("Find!\n");
		return;
	}
	else
	{
		if (data > BT->data)
		{
			if (NULL != BT->rchild)
			{
				Search(BT->rchild,data);
			}
		}
		else
		{
			if (NULL != bt->lchild)
			{
				Search(BT->lchild,data);
			}
		}
	}
}
// Insert a value to
void Insert(BiTree BT,Elemtype data)
{
	BiNode *tmp;
	if (NULL == BT)
	{
		BT =(BiTree)malloc(sizeof(BiNode));
		BT->data = data;
		BT->lchild =NULL;
		BT->rchild =NULL;
	}

	if (BT->data >data)
	{
		if (NULL == BT->lchild)
		{
			tmp = (BiTree)malloc(sizeof(BiNode));
			tmp->data = data;
			tmp->lchild = tmp->rchild =NULL;
			BT->lchild = tmp;
		}
		else
			Insert(BT->lchild,data);
	}
	else
	{
		if (NULL == BT->rchild)
		{
			tmp = (BiTree)malloc(sizeof(BiNode));
			tmp->data = data;
			tmp->child = tmp->rchild =NULL;
			BT->rchild = tmp;
		}
		else
			Insert(BT->rchild,data);
	}
}
// count the num of leaves
int CountLeaves(BiTree BT)
{
	int count = 0;
	if (!BT->lchild && !BT->rchild)
	{
		count++;
	}
	CountLeaves(BT->lchild);
	CountLeaves(BT->rchild);

	return count;
}
// count the depth 
int BiTreeDepth(BiTree BT)
{
	int lchilddepth,rchilddepth;
	if (NULL == BT)
	{
		return 0;
	}
	else
	{
		lchilddepth = BiTreeDepth(BT->lchild);
		rchilddepth = BiTreeDepth(BT->rchild);
	}
	return (lchilddepth > rchilddepth) ? (lchilddepth +1):(rchilddepth +1);
}

void PrintTree(BiTree BT)
{
	
}
int main(int argc, char const *argv[])
{
	BiTree BT;
	CreatBiTree();
	return 0;
}