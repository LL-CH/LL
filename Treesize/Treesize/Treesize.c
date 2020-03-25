#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"Treesize.h"
#include"queal.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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

// ����������
void BinaryTreeDestory(BTNode* root){
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

// �������ڵ����
int BinaryTreeSize(BTNode* root){
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root){
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k){
	if (root == NULL) 
		return 0;
	if (k == 1) 
		return 1;
	else
		return BinaryTreeLeavelKSize(root -> left, k - 1) + BinaryTreeLeavelKSize(root->right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x){
	if (root == NULL)
		return;
	if (root->_data == x)
		return root;
	//������ʱ������
	BTNode* ret = BinaryTreeFind(root->left, x);
	if (ret){
		return ret;
	}
	//����û�ҵ�,������
	ret = BinaryTreeFind(root->right, x);
	if (ret){
		return ret;
	}
	return NULL;
}

// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root){
	if (root == NULL)
		return;
	//��->��->��
	printf("%d ", root->_data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// �������������
void BinaryTreeInOrder(BTNode* root){
	if (root == NULL)
		return;
	//��->��->��
	BinaryTreeInOrder(root->left);
	printf("%d ", root->_data);
	BinaryTreeInOrderr(root->right);
}

// �������������
void BinaryTreePostOrder(BTNode* root){
	if (root == NULL)
		return;
	//��->��-��
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->_data);
}

// �������
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

// �ж϶������Ƿ�����ȫ������
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