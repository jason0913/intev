#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 统计每一个字母出现的次数，并且排序

typedef struct node
{
	char ch;
	int count;
	struct node *lchild;
	struct node *rchild;
}TREE;
//   Sort by the TREE

TREE* addtree(char c,TREE *root)
{
	if(root == NULL)
	{
		root = (TREE*)malloc(sizeof(TREE));
		if(root == NULL)
		{
			perror("malloc TREE failed");
		}
		root->ch = c;
		root->count = 1;
		root->lchild = NULL;
		root->rchild = NULL;
	}
	else if(c == root->ch)
		root->count ++;
	else if(c < root->ch)
		root->lchild = addtree(c,root->lchild);
	else if (c > root->ch)
		root->rchild = addtree(c,root->rchild);
	return root;
}
void printtree(TREE *root)
{
	/* printtree(root->lchild);
	if(root != NULL)
		printf("%c",root->ch);
	printtree(root->rchild); */
	if(root != NULL)
	{
		printtree(root->lchild);
		printf("%c:%d ", root->ch,root->count);
		printtree(root->rchild);
	}
}
int main()
{
	int c;
	TREE *root;
	root = NULL;

	while((c = getchar()) != '\n')
	{
		if(c != ' ')
			root = addtree(c,root);
	}
	printtree(root);
	exit(0);
}
