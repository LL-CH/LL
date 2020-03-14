#include<stdio.h>
#include"Treesize.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi){

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

}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root){

}