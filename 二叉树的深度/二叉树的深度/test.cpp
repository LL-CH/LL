struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//�ݹ�汾
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
		//���������ÿһ�������ݾ���ȼ�һ
		while (!q.empty()){
			//����q�����ݸ���
			int size = q.size();
			//ɾ����������
			for (int i = 0; i<size; i++){
				TreeNode* tmp = q.front();
				q.pop();
				//�����һ������
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