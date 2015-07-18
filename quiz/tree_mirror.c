/*
the mirror of a tree
*/
#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode
{
	int value;
	struct BinaryTreeNode *leftchild;
	struct BinaryTreeNode *rightchild;
};

typedef struct BinaryTreeNode BinTreeNode;

BinTreeNode * InitRoot()
{
	BinTreeNode *root;
	root = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	if (root)
	{
		printf("Input root data\n");
		scanf("%d",root->value);
		root->leftchild = NULL;
		root->rightchild= NULL;

		return root;
	}
	else
		return NULL;
}
BinTreeNode *FindNode(BinTreeNode *root,int data)
{
	BinTreeNode * ptr;
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
			if (ptr =FindNode(root->leftchild,data))
			{
				return ptr;
			}
			else if (ptr = FindNode(root->rightchild,data))
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
	BinTreeNode *pnode,*parent;
	int data;
	char menusel;

	pnode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	if (pnode)
	{
		printf("Input new node data\n");
		scanf("%d",&(pnode->value));
		pnode->leftchild =NULL;
		pnode->rightchild =NULL;

		printf("Input parent node data\n");
		scanf("%d",&data);
		parent = FindNode(root,data);

		if(NULL == parent)
		{
			printf("Not find parent\n");
			free(pnode);
		}
		else
		{
			printf("l:leftchild,r:rightchild\n");
			scanf("%c",&menusel);
			switch(menusel)
			{
				case 'l':
				if (NULL != parent->leftchild)
				{
					printf("parent has leftchild\n");
					break;
				}
				parent->leftchild = pnode;
				printf("Add to leftchild\n");
				break;

				case 'r':
				if (NULL != parent->rightchild)
				{
					printf("parent has rightchild\n");
					break;
				}
				parent->rightchild =pnode;
				printf("Add to rightchild\n");
				break;

				default:
				printf("invalid choose\n");
				break;
			}
		}
	}
}
void PreTree(BinTreeNode *root)
{
	if (NULL != root)
	{
		printf("%d ", root->value);;
		PreTree(root->leftchild);
		PreTree(root->rightchild);
	}
}
void swap(struct BinaryTreeNode *leftchild,struct BinaryTreeNode *rightchild)
{
	struct BinaryTreeNode *tmp = leftchild;
	leftchild = rightchild;
	rightchild = tmp;
}
void MirrorRecursive(struct BinaryTreeNode *PNode)
{
	if (NULL == PNode)
	{
		return;
	}
	if (NULL != PNode && NULL== PNode->leftchild && NULL== PNode->rightchild)
	{
		return;
	}

	swap(PNode->leftchild,PNode->rightchild);
	if (PNode->leftchild)
	{
		MirrorRecursive(PNode->leftchild);
	}
	if (PNode->rightchild)
	{
		MirrorRecursive(PNode->rightchild);
	}
}

int main(int argc, char const *argv[])
{
	BinTreeNode *root;
	root = InitRoot();
	int i;
	for (i = 0; i < 3; ++i)
	{
		AddNode(root);
	}
	PreTree(root);
	return 0;
}
