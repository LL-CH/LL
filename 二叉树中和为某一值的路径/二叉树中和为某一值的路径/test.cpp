 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<vector<int>> vv;
	void finddath(TreeNode* root, int sum, vector<int> &path){
		if (root == nullptr)
			return;
		//找到一条路径
		if (root->left == nullptr&&root->right == nullptr&&root->val - sum == 0){
			path.push_back(root->val);
			vv.push_back(path);
			path.pop_back();
			return;
		}
		path.push_back(root->val);
		//每走一个节点，就把sum减小val
		finddath(root->left, sum - root->val, path);
		finddath(root->right, sum - root->val, path);
		path.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> path;
		finddath(root, sum, path);
		return vv;
	}
};