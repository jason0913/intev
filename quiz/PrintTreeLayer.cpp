#include <iostream>
#include <deque>
#include <stdlib.h>

using namespace std;

struct BinTreeNode
{
	int value;
	struct BinTreeNode *leftchild;
	struct BinTreeNode *rightchild;
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

struct BinTreeNode *CreatBiTree()
{
	char ch;
	struct BinTreeNode *Tree;

	cout<<"input node"<<endl;
	cin >>ch;
	if ('#' == ch)
	{
		Tree = NULL;
	}
	else
	{
		Tree = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
		Tree->value = ch;
		Tree->leftchild = CreatBiTree();
		Tree->rightchild = CreatBiTree();
	}
	return Tree;
}

void PrintTreeByLayer(struct BinTreeNode *PTreeRoot)
{
	if (NULL == PTreeRoot)
	{
		return;
	}
	deque <struct BinTreeNode *> deque_tree_node;
	deque_tree_node.push_back(PTreeRoot);

	while(deque_tree_node.size())
	{
		struct BinTreeNode *PNode = deque_tree_node.front();
		deque_tree_node.pop_front();

		cout<<PNode->value<<" ";

		if (PTreeRoot->leftchild)
		{
			deque_tree_node.push_back(PTreeRoot->leftchild);
		}
		if (PTreeRoot->rightchild)
		{
			deque_tree_node.push_back(PTreeRoot->rightchild);
		}
	}
}

void PreOrder(struct BinTreeNode *PTreeRoot)
{
	if (NULL != PTreeRoot)
	{
		cout <<PTreeRoot->value<<" ";
		PreOrder(PTreeRoot->leftchild);
		PreOrder(PTreeRoot->rightchild);
	}
}
int main(int argc, char const *argv[])
{
	// struct BinTreeNode *bitree = CreatBiTree();
	BinTreeNode *bitree;
	bitree = InitTree();
	cout<<"input nodes num"<<endl;
	int count;
	cin>>count;
	int i;
	for (int i = 0; i < count; ++i)
	{
		AddNode(bitree);
	}
	cout<<"PrintTreeByLayer-------"<<endl;
	PrintTreeByLayer(bitree);
	cout<<"PreOrder-------"<<endl;
	PreOrder(bitree);
	return 0;
}