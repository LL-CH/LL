#include<stdio.h>
#include"Treesize.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi){

}

// ����������
void BinaryTreeDestory(BTNode** root){

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

}

// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root){

}

// �������������
void BinaryTreeInOrder(BTNode* root){

}

// �������������
void BinaryTreePostOrder(BTNode* root){

}

// �������
void BinaryTreeLevelOrder(BTNode* root){

}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root){

}