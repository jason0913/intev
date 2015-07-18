/* 
* @Author: root
* @Date:   2015-07-01 08:32:57
* @Last Modified by:   root
* @Last Modified time: 2015-07-01 10:03:51
 trun BStree to linklist
*/

#include <iostream>

using namespace std;

struct treenode
{
	int value;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode BSTreeNode;

BSTreeNode * InitRoot()
{
	BSTreeNode *root;
	root = new BSTreeNode;
	if (root)
	{
		cout<<"Input root data"<<endl;
		cin>>root->value;
		root->left = NULL;
		root->right = NULL;

		return root;
	}
	else
		return NULL;
}
BSTreeNode * FindNode(BSTreeNode *root,int data)
{
	BSTreeNode *ptr;
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
		if (ptr = FindNode(root->left,data))
		{
			return ptr;
		}
		else if (ptr = FindNode(root->right,data))
		{
			return ptr;
		}
		else
			return NULL;
	}
}
void AddTreeNode(BSTreeNode *root)
{
	BSTreeNode *pnode,*parent;
	char menusel;
	int pdata;
	
	pnode = new BSTreeNode;
	if (pnode)
	{
		cout<<"Input node data"<<endl;
		cin>>pnode->value;
		pnode->left =NULL;
		pnode->right =NULL;

		cout<<"Input parent data"<<endl;
		cin>>pdata;
		parent = FindNode(root,pdata);
		if (NULL == parent)
		{
			cout<<"no parent"<<endl;
			return;
		}
		cout<<"l:left,r:right"<<endl;
		cin>>menusel;
		switch(menusel)
		{
			case 'l':
				if (NULL != parent->left)
				{
					cout<<"left has node"<<endl;
					break;
				}
				parent->left = pnode;
				cout<<"add "<<pnode->value<<" to left "<<parent->value<<endl;
				break;
			case 'r':
				if (NULL != parent->right)
				{
					cout<<"right has node"<<endl;
					break;
				}
				parent->right = pnode;
				cout<<"add "<<pnode->value<<" to right"<<parent->value<<endl;
				break;
			default:
				cout<<"invalid choose"<<endl;
				break;
		}
	}
}
void helper(BSTreeNode *&head,BSTreeNode *&tail,BSTreeNode *root)
{
	if (NULL == root)
	{
		tail = NULL;
		head = NULL;
		return;
	}
	BSTreeNode *lt,*rh;
	helper(head,lt,root->left);
	helper(rh,tail,root->right);
	if (NULL != lt)
	{
		lt->right = root;
		root->left = lt;
	}
	else
		head = root;
	if (NULL != rh)
	{
		root->right = rh;
		rh->left = root;
	}
	else
		tail = root;
}
BSTreeNode *TreeToLink(BSTreeNode *root)
{
	BSTreeNode *head,*tail;
	helper(head,tail,root);
	return head;
}
void PreTree(BSTreeNode *root)
{
	if (root)
	{
		cout<<root->value<<" ";
		PreTree(root->left);
		PreTree(root->right);
	}
}
void Inorder(BSTreeNode *root)
{
	if (root)
	{
		Inorder(root->left);
		cout<<root->value<<" ";
		Inorder(root->right);
	}
}
void PostTree(BSTreeNode *root)
{
	if (root)
	{
		PostTree(root->left);
		PostTree(root->right);
		cout<<root->value<<" ";
	}
}
void PrintLink(BSTreeNode *root)
{
	BSTreeNode *ptr;
	ptr = root;
	while(ptr)
	{
		cout<<ptr->value<<" ";
		ptr = ptr->right;
	}
}
int main(){

	BSTreeNode *root;
	root = InitRoot();
	int i;
	for (int i = 0; i < 2; ++i)
	{
		AddTreeNode(root);
	}
	cout<<"PreTree:"<<endl;
	PreTree(root);
	cout<<"\nInorder:"<<endl;
	Inorder(root);
	cout<<"\nPostTree:"<<endl;
	PostTree(root);

	BSTreeNode *head;
	head = TreeToLink(root);
	cout<<"TreeToLink:"<<endl;
	PrintLink(head);
    return 0;
}