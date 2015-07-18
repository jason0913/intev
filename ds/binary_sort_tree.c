#include "ds.h"

typedef int ElemType;

typedef struct TreeNode
{
	ElemType value;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode,*BinTreeNode *

typedef struct TreeNode BinTreeNode;

BinTreeNode *InitTree()
{
	BinTreeNode *Tnode;
	Tnode =new BinTreeNode;
	if (Tnode)
	{
		cout<<"Init root node"<<endl;
		cin>>Tnode->value;
		Tnode->left =NULL;
		Tnode->right =NULL;

		if (NULL != Tnode)
		{
			return Tnode;
		}
		else
			return NULL;
	}
	return NULL;
}

BinTreeNode *FindNode(BinTreeNode *root,int data)
{
	BinTreeNode *ptr;
	if (NULL == root)
	{
		return NULL;
	}
	else
	{
		if (data == root->value)
		{
			return root;
		}
		else
		{
			if (ptr =FindNode(root->left,data))
			{
				return ptr;
			}
			else if (ptr =FindNode(root->right,data))
			{
				return ptr;
			}
			else
				return NULL;
		}
	}
}
void AddNode(BinTreeNode *root)
{
	BinTreeNode *pnode ,*parent;
	int data;
	char menusel;

	if (pnode = new BinTreeNode)
	{
		cout<<"Add node data:"<<endl;
		cin>> pnode->value;
		pnode->left =NULL;
		pnode->right =NULL;

		cout<<"Input parent node:"<<endl;
		cin>>data;
		parent = FindNode(root,data);
		if (NULL== parent)
		{
			cout<<"not find parent node"<<endl;
			delete pnode;
		}
		cout<<"l:leftchild,r:rightchild"<<endl;
		do
		{
			cin>>menusel;
			if ('l'== menusel || 'r'==menusel)
			{
				switch(menusel)
				{
					case 'l':
					if (NULL != parent->left)
					{
						cout<<"parent left not NULL"<<endl;
						break;
					}
					else
					{
						parent->left = pnode;
						cout<<"add "<<pnode->value<<" to left" <<parent->value<< endl;
					}
						break;
					case 'r':
					if (NULL != parent->right)
					{
						cout<<"parent right not NULL"<<endl;
						break;
					}
					else
					{
						parent->right = pnode;
						cout<<"add "<<pnode->value <<" to right "<<parent->value<<endl;
					}
						break;
					default:
						cout<<"invalid choose"<<endl;
						break;
				}
			}
		}while('l' !=menusel && 'r'!=menusel);
	}
}
void PreTree(BinTreeNode *root)
{
	if (NULL != root)
	{
		cout<<root->value<<" ";
		PreTree(root->left);
		PreTree(root->right);
	}
}

BinTreeNode *BSTSearch(BinTreeNode *BT,valueType key,BinTreeNode *q)
{
	// p point to compareing node
	BinTreeNode *p = BT;
	// q is the father of node p
	q = NULL;

	while(p)
	{
		if (key == p->value)
		{
			return p;
		}
		else if (key < p->value)
		{
			q = p;
			p = p->left;
		}
		else
		{
			q = p;
			p = p->right;
		}
	}
	return p;
}

BinTreeNode *BSTSearch_Recur(BinTreeNode *BT,valueType key)
{
	if (NULL!= BT || key == BT->value)
	{
		return BT;
	}
	else if (key < BT->value)
	{
		return BSTSearch_Recur(BT->left,key);
	}
	else
		return BSTSearch_Recur(BT->right,key);
}

int InsertBST(BinTreeNode *BT,ElemType e)
{
	int falg = 0;
	BinTreeNode *q;
	if (!BSTSearch(BT,e,q))
	{
		BinTreeNode *s = (BinTreeNode *malloc(sizeof(TreeNode));
		if (NULL == s)
		{
			perror("malloc TreeNode error");
			exit(-1);
		}
		s->value = e;
		s->right = NULL;
		s->left = NULL;

		if (!q)
		{
			BT = s;
		}
		else
		{
			if (e > q->value)
			{
				q->right =s;
			}
			else
				q->left =s;
		}
		falg =1;
	}
	return falg;
}

int DeleteBSTNode(BinTreeNode *BT,ElemType key)
{
	BinTreeNode *p,f;
	BinTreeNode *q;
	int falg = 0;
	p = BSTSearch(BT,key,f);
	if (p)
	{
		/* code */
	}
}
void PrintTree(BinTreeNode *BT)
{
	if (NULL != BT)
	{
		PrintTree(BT->left);
		printf("%d \n", BT->value);
		PrintTree(BT->right);
	}
}
int main(int argc, char const *argv[])
{
	BinTreeNode *BT;
	InsertBST(BT,1);
	PrintTree(BT);
	// InsertBST(BT,2);
	return 0;
}