
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool issame(TreeNode* &root1, TreeNode* &root2){
		//�ڵ㶼Ϊ�գ�������
		if (root1 == nullptr && root2 == nullptr)
			return true;
		//ֻ��һ��Ϊ�գ��ڵ㲻��ͬ
		if (root1 == nullptr || root2 == nullptr)
			return false;
		if (root1->val != root2->val)
			return false;
		//�ж���һ��
		return issame(root1->left, root2->right) && issame(root1->right, root2->left);

	}
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;
		return issame(root, root);
	}
};