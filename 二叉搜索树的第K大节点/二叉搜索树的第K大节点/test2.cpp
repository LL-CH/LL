
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int ret = 0;
	int n = 0;
	//����������򣬵�k�󣬵��ű���k����
	//��-��-��
	void core(TreeNode* root, int k){
		if (root->right != nullptr)
			core(root->right, k);
		if (++n == k){
			ret = root->val;
			return;
		}
		if (root->left != nullptr)
			core(root->left, k);
	}

	int kthLargest(TreeNode* root, int k) {
		core(root, k);
		return ret;
	}
};