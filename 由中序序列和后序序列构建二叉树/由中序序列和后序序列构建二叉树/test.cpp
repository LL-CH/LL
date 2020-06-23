
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
		// indexԽ��ʱ��˵�����еĽڵ��Ѿ��������
		TreeNode* pRoot = nullptr;
		if (index < 0)
			return pRoot;

		// ��ԭ���ڵ�
		pRoot = new TreeNode(postorder[index]);

		// ���������������Ҹ��ڵ��λ�ã����ڵ�������Ǹ������������Ҳ�Ľڵ��Ǹ���������
		int mid = begin;
		while (mid < end)
		{
			if (inorder[mid] == postorder[index])
				break;

			mid++;
		}

		// ������������ڣ��ݹ鴴�����ڵ��������
		if (mid + 1 < end)
		{
			pRoot->right = _buildTree(inorder, --index, postorder, mid + 1, end);
		}

		// ���������ڣ��ݹ鴴�����ڵ�������
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