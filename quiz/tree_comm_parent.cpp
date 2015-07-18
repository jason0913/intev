/* 
* @Author: root
* @Date:   2015-07-06 10:35:24
* @Last Modified by:   root
* @Last Modified time: 2015-07-06 11:00:12
*/

#include <iostream>

using namespace std;

typedef struct BiNode
{
	int value;
	struct BiNode *lchild,*rchild;
}BiTNode;

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

void PreTree(BiTNode *root)
{
	if (root)
	{
		cout<<root->value<<" ";
		PreTree(root->lchild);
		PreTree(root->rchild);
		cout<<endl;
	}
}
// in BST two nodes has commom parent
BiTNode *CommomParent(BiTNode *b1,BiTNode *b2,BiTNode *root)
{
	if (NULL == root)
	{
		return NULL;
	}
	int min,max;
	min =(b1->value < b2->value ? b1->value:b2->value);
	max =(b1->value > b2->value ? b1->value:b2->value);
	while(root)
	{
		if (root->value > min && root->value < max)
		{
			return root;
		}
		else if (root->value > max)
		{
			root = root->lchild;
		}
		else
			root = root->rchild;
	}
	return NULL;
}
int main(){

	BiTNode *root;
	root = InitRoot();
	int i;
	cout<<"Bulid BST:"<<endl;
	for (int i = 0; i < 3; ++i)
	{
		AddTreeNode(root);
	}
	PreTree(root);
	BiTNode *b1 = root->lchild;
	BiTNode *b2 = root->lchild->lchild;
	BiTNode *Commom;
	Commom = CommomParent(b1,b2,root);
	cout<<"CommomParent"<<Commom->value<<endl;
    return 0;
}