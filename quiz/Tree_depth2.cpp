/*
the tree is balance or not
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
bool IsBalance(BinTreeNode *pRoot)
{
	if (NULL == pRoot)
	{
		return true;
	}
	int lefthight = TreeDepth(pRoot->leftchild);
	int righthight = TreeDepth(pRoot->righchild);

	int diff = lefthight - righthight;
	if (diff > 1 || diff < -1)
	{
		return false;
	}
	return IsBalance(pRoot->leftchild) && IsBalance(pRoot->righchild);
}
bool IsBalancePost(BinTreeNode *pRoot,int *pdepth)
{
	if (NULL == pRoot)
	{
		*pdepth =0;
		return true;
	}
	int left ,right;
	if (IsBalancePost(pRoot->leftchild,&left) && IsBalancePost(pRoot->righchild,&right))
	{
		int diff = left -right;
		if (diff <=1 && diff >=-1)
		{
			*pdepth =1+(left >right ? left:right);
			return true;
		}
	}
	return false;

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
	bool res = false;
	cout<<"PreTree:";
	PreTree(root);
	cout<<endl<<"-----"<<endl;
	cout<<"InorderTree:";
	InorderTree(root);
	cout<<endl<<"-----"<<endl;
	cout<<"PostTree:";
	PostTree(root);
	cout<<endl<<"-----"<<endl;
	res = IsBalance(root);
	cout<<"tree balance:"<<res<<endl;
	int depth = 0;
	cout<<"tree balance:"<<IsBalancePost(root,&depth)<<endl;

	return 0;
}