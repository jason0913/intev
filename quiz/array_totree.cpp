/* 
* @Author: root
* @Date:   2015-07-16 11:26:06
* @Last Modified by:   root
* @Last Modified time: 2015-07-16 11:42:32
  put array ele in a tree
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode
{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode BinTreeNode;

BinTreeNode * ArrayToTree(int array[],int start, int end)
{
	if ((start > end) || (NULL == array))
	{
		return NULL;
	}
	int m = (start + end) /2;

	BinTreeNode *root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	root->value = array[m];
	root->left = ArrayToTree(array,start,m-1);
	root->right = ArrayToTree(array,m+1,end);

	return root;
}
void PreOrder(BinTreeNode *root)
{
	if (root)
	{
		cout<<root->value <<" ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
	// cout<<"----";
}
void Inorder(BinTreeNode *root)
{
	if (root)
	{
		Inorder(root->left);
		cout<<root->value <<" ";
		Inorder(root->right);
	}
}
int main(){

	int array[] ={1,2,3,4,5,6};
	BinTreeNode *root = NULL;
	root = ArrayToTree(array,0,5);
	cout<<"PreOrder:"<<endl;
	PreOrder(root);
	cout<<endl;
	cout<<"Inorder:"<<endl;
	Inorder(root);
    return 0;
}