
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* _buildTree(vector<int>& inorder, int& index, vector<int>& postorder, int begin, int end)
	{
		// index越界时，说明树中的节点已经创建完毕
		TreeNode* pRoot = nullptr;
		if (index < 0)
			return pRoot;

		// 还原根节点
		pRoot = new TreeNode(postorder[index]);

		// 在中序遍历结果中找根节点的位置，根节点左侧是是根的左子树，右侧的节点是根的右子树
		int mid = begin;
		while (mid < end)
		{
			if (inorder[mid] == postorder[index])
				break;

			mid++;
		}

		// 如果右子树存在，递归创建根节点的右子树
		if (mid + 1 < end)
		{
			pRoot->right = _buildTree(inorder, --index, postorder, mid + 1, end);
		}

		// 左子树存在，递归创建跟节点左子树
		if (begin < mid)
		{
			pRoot->left = _buildTree(inorder, --index, postorder, begin, mid);
		}

		return pRoot;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		int index = postorder.size() - 1;
		return _buildTree(inorder, index, postorder, 0, inorder.size());
	}
};