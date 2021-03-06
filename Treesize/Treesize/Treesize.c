#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"Treesize.h"
#include"queal.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi){
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}

	BTNode * cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = a[*pi];
	(*pi)++;

	cur->left = BinaryTreeCreate(a,n,pi);
	cur->right = BinaryTreeCreate(a,n,pi);

	return cur;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode* root){
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root){
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root){
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k){
	if (root == NULL) 
		return 0;
	if (k == 1) 
		return 1;
	else
		return BinaryTreeLeavelKSize(root -> left, k - 1) + BinaryTreeLeavelKSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x){
	if (root == NULL)
		return;
	if (root->_data == x)
		return root;
	//不等于时找左树
	BTNode* ret = BinaryTreeFind(root->left, x);
	if (ret){
		return ret;
	}
	//左树没找到,找右树
	ret = BinaryTreeFind(root->right, x);
	if (ret){
		return ret;
	}
	return NULL;
}

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root){
	if (root == NULL)
		return;
	//根->左->右
	printf("%d ", root->_data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root){
	if (root == NULL)
		return;
	//左->根->右
	BinaryTreeInOrder(root->left);
	printf("%d ", root->_data);
	BinaryTreeInOrderr(root->right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root){
	if (root == NULL)
		return;
	//左->右-根
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root){
	Queue qu;
	BTNode * cur;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueEmpty(&qu))
	{
		cur = QueueFront(&qu);

		putchar(cur->_data);

		if (cur->left)
		{
			QueuePush(&qu, cur->left);
		}

		if (cur->right)
		{
			QueuePush(&qu, cur->right);
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root){
	Queue qu;
	BTNode * cur;
	int tag = 0;

	QueueInit(&qu);
	QueuePush(&qu, root);

	while (!QueueEmpty(&qu)){
		cur =  QueueFront(&qu);
		putchar(cur->_data);
		if (cur->right && !cur->left)
		{
			return 0;
		}
		if (tag && (cur->right || cur->left))
		{
			return 0;
		}
		if (cur->left)
		{
			QueuePush(&qu, cur->left);
		}
		if (cur->right)
		{
			QueuePush(&qu, cur->right);
		}
		else
		{
			tag = 1;
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return 1;
}