/*
usage of a bintree
*/
#include <iostream>

using namespace std;

struct TreeNode
{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
};

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
						cout<<"add "<<data<<" to left" <<parent->value<< endl;
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
						cout<<"add "<<data <<" to right "<<parent->value<<endl;
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
void Inorder(BinTreeNode *root)
{
	if (NULL != root)
	{
		Inorder(root->left);
		cout<<root->value<<" ";
		Inorder(root->right);
	}
}
void PostTree(BinTreeNode *root)
{
	if (NULL != root)
	{
		PostTree(root->left);
		PostTree(root->right);
		cout<<root->value<<" ";
	}
}
int TreeDepth(BinTreeNode *root)
{
	if (NULL ==root)
	{
		return 0;
	}
	int depthleft,depthright;
	depthleft = TreeDepth(root->left);
	depthright = TreeDepth(root->right);
	if (depthleft)
	{
		return ++depthleft;
	}
	else
	{
		return ++depthright;
	}
}
void Clear(BinTreeNode *root)
{
	if (NULL != root)
	{
		Clear(root->left);
		Clear(root->right);
		delete root;
	}
}
int main(int argc, char const *argv[])
{
	BinTreeNode *root;
	root = InitTree();
	int i;
	for (int i = 0; i < 3; ++i)
	{
		AddNode(root);
	}
	cout<<"\nPreTree-----"<<endl;
	PreTree(root);
	cout<<"\n Inorder-----"<<endl;
	Inorder(root);
	cout<<"\n PostTree----"<<endl;
	PostTree(root);
	cout<<"\nTreeDepth:"<<TreeDepth(root)<<endl;
	Clear(root);
	return 0;
}