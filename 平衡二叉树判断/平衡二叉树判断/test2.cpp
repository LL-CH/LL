/*后序遍历解题*/
/*
使用后序遍历的方式遍历二叉树的每个节点，那么在遍历到一个节点之前我们就已经
遍历了它的左右子树。只要在每个节点的时候记录它的深度(某一节点的深度等于它到叶节点的路径的长度）
就可以判断每个节点是不是平衡的
*/
class Solution {
public:
	bool isBalanced(TreeNode* root)
	{
		if (root == nullptr) return true;
		int depth = 0;
		return isBalanced(root, depth);
	}

	bool isBalanced(TreeNode* root, int &depth) {
		if (root == nullptr) {
			depth = 0;
			return true;
		}
		int left = 0, right = 0;
		if (isBalanced(root->left, left) && isBalanced(root->right, right))
		{
			int diff = left - right;
			if (abs(diff) <= 1)
			{
				depth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}
};