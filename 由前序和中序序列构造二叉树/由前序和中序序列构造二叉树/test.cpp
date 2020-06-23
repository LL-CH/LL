
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
		// indexԽ��ʱ��˵�����еĽڵ��Ѿ��������
		TreeNode* Root = nullptr;
		if (index >= preorder.size())
			return Root;

		// ��ԭ���ڵ�
		Root = new TreeNode(preorder[index]);

		// ���������������Ҹ��ڵ��λ�ã����ڵ�������Ǹ������������Ҳ�Ľڵ��Ǹ���������
		int mid = begin;
		while (mid < end)
		{
			if (inorder[mid] == preorder[index])
				break;

			mid++;
		}

		// ���������ڣ��ݹ鴴�����ڵ�������
		if (begin < mid)
		{
			Root->left = _buildTree(preorder, ++index, inorder, begin, mid);
		}

		// ������������ڣ��ݹ鴴�����ڵ��������
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