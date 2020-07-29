
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr)
			return root;
		if (root->left == nullptr && root->right == nullptr)
			return root;
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		if (root->left)
			mirrorTree(root->left);
		if (root->right)
			mirrorTree(root->right);

		return root;

	}
};