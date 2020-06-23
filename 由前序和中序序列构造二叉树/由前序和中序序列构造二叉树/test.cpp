
struct TreeNode {
     int val;     
	 TreeNode *left;
	 TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* _buildTree(vector<int>& preorder, int& index, vector<int>& inorder, int begin, int end)
	{
		// index越界时，说明树中的节点已经创建完毕
		TreeNode* Root = nullptr;
		if (index >= preorder.size())
			return Root;

		// 还原根节点
		Root = new TreeNode(preorder[index]);

		// 在中序遍历结果中找根节点的位置，根节点左侧是是根的左子树，右侧的节点是根的右子树
		int mid = begin;
		while (mid < end)
		{
			if (inorder[mid] == preorder[index])
				break;

			mid++;
		}

		// 左子树存在，递归创建跟节点左子树
		if (begin < mid)
		{
			Root->left = _buildTree(preorder, ++index, inorder, begin, mid);
		}

		// 如果右子树存在，递归创建根节点的右子树
		if (mid + 1 < end)
		{
			Root->right = _buildTree(preorder, ++index, inorder, mid + 1, end);
		}

		return Root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int index = 0;
		return _buildTree(preorder, index, inorder, 0, inorder.size());
	}
};