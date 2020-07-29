
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool issame(TreeNode* A, TreeNode* B){
		//B为空，说明比完了
		if (B == nullptr)
			return true;
		//A为空，说明A中没B
		if (A == nullptr)
			return false;
		//值不相同，说明节点不同
		if (A->val != B->val)
			return false;
		//比较左右子树是否相同
		return issame(A->left, B->left)
			&& issame(A->right, B->right);
	}

	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr)
			return false;
		bool res = false;
		//找到初始位置
		if (A->val == B->val)
			//从该起始位置开始，查找是否一致
			res = issame(A, B);
		//不一致，在A树的左子树使用相同的方式找找
		if (!res)
			res = isSubStructure(A->left, B);
		//还不一致，去右树找
		if (!res)
			res = isSubStructure(A->right, B);

		return res;
	}
};