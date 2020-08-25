
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	//求树的高度
	int maxDepth(TreeNode*root){
		if (root == nullptr)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		//取高度差的绝对值
		if (abs(left - right)>1)
			return false;

		return isBalanced(root->left) && isBalanced(root->right);
	}
};