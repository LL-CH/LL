class Solution {
public:
	//ÖĞĞò±éÀúÓĞĞò
	vector<int> ans;
	void traverse(TreeNode* root){
		if (root == NULL)
			return;
		traverse(root->left);
		ans.push_back(root->val);
		traverse(root->right);
	}

	int kthLargest(TreeNode* root, int k) {
		traverse(root);
		return ans[ans.size() - k];
	}

};