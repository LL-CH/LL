/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/



int Depth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	int leftDepth = Depth(root->left);
	int rightDepth = Depth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}


bool isBalanced(struct TreeNode* root){
	if (root == NULL){
		return true;
	}
	int leftDepth = Depth(root->left);
	int rightDepth = Depth(root->right);


	return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left) && isBalanced(root->right);
}