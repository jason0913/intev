/*
the depth of a bintree
*/
#include <iostream>

using namespace std;

struct bintreenode
{
	int value;
	struct bintreenode *leftchild;
	struct bintreenode *righchild;
};

typedef struct bintreenode BinTreeNode;

int TreeDepth(BinTreeNode *pRoot)
{
	if (NULL == pRoot)
	{
		return 0;
	}
	int leftdepth = TreeDepth(pRoot->leftchild);
	int rightdepth = TreeDepth(pRoot->righchild);

	return (leftdepth > rightdepth)? (leftdepth+1) : (rightdepth+1);
}

BinTreeNode * CreatTree()
{
	int n;
	BinTreeNode * T;
	cout<<"CreatTree end with -1"<<endl;
	cin>>n;
	if (-1 == n)
	{
		T =NULL;
	}
	else
	{
		T = new BinTreeNode;
		T->value = n;
		T->leftchild = CreatTree();
		T->righchild = CreatTree();
	}

	return T;
}

void PreTree(BinTreeNode *root)
{
	if (NULL != root)
	{
		cout<<root->value<<" ";
		PreTree(root->leftchild);
		PreTree(root->righchild);
	}
}
void InorderTree(BinTreeNode *root)
{
	if (NULL != root)
	{
		InorderTree(root->leftchild);
		cout<<root->value<<" ";
		InorderTree(root->righchild);
	}
}
void PostTree(BinTreeNode *root)
{
	if (NULL != root)
	{
		PostTree(root->leftchild);
		PostTree(root->righchild);
		cout<<root->value<<" ";
	}
}
int main(int argc, char const *argv[])
{
	BinTreeNode *root;
	root = CreatTree();
	int depth = 0;
	depth = TreeDepth(root);
	cout<<"PreTree:";
	PreTree(root);
	cout<<endl<<"-----"<<endl;
	cout<<"InorderTree:";
	InorderTree(root);
	cout<<endl<<"-----"<<endl;
	cout<<"PostTree:";
	PostTree(root);
	cout<<endl<<"-----"<<endl;
	cout<<"tree depth:"<<depth<<endl;
	return 0;
}