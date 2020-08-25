struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//递归版本
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);

		return 1 + max(left, right);
	}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int depth = 0;
		//层序遍历，每一层有数据就深度加一
		while (!q.empty()){
			//重置q的数据个数
			int size = q.size();
			//删除本层数据
			for (int i = 0; i<size; i++){
				TreeNode* tmp = q.front();
				q.pop();
				//添加下一层数据
				if (tmp->left)
					q.push(tmp->left);
				if (tmp->right)
					q.push(tmp->right);
			}
			depth++;
		}
		return depth;
	}
};