/*
all the path value in the binary tree
*/

#include <iostream>
#include <vector>
#include <iterator>

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

void FindTreePath(BinTreeNode *PRoot, vector<int> & path,int &sum)
{
	sum += PRoot->value;
	path.push_back(PRoot->value);

	bool Isleaf = (NULL == PRoot->left) && (NULL == PRoot->right);
	if (Isleaf)
	{
		cout <<"path is:";
		std::vector<int>:: iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
		{
			cout <<*iter <" ";
		}
		cout<<endl;
	}

	if (NULL != PRoot->left)
	{
		FindTreePath(PRoot->left,path,sum);
	}
	if (NULL != PRoot->right)
	{
		FindTreePath(PRoot->right,path,sum);
	}

	sum -= PRoot->value;
	path.pop_back();
}

int main(int argc, char const *argv[])
{
	BinTreeNode *root = InitTree();
	int i;
	int count;
	cout<<"Input nodes num"<<endl;
	cin>>count;
	for (i = 0; i < count; ++i)
	{
		AddNode(root);
	}
	PreTree(root);
	vector<int> p(0);
	vector<int> &path =p;
	int s=0;
	int &sum =s;
	FindTreePath(root,path,sum);
	return 0;
}
