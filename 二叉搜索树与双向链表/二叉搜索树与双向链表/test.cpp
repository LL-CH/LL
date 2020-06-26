/*
˼·��
1. ����ֱ�ӷ���
2. �ǿ�
a. �ڶ������������ҵ�������׽ڵ�
b. Ҫת��Ϊ���������������������������պÿ��Եõ�һ���������У���˲�����������Ĺ������ת������ת�������У�ֻ��Ҫ�ı�ÿ���ڵ�����ָ�����ָ�򼴿ɡ�
����ʵ�֣��ο�����
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
}

class Solution {
public:
	// pPrev��Ǹո�ת���Ľڵ㣬pRoot��ʾ����Ҫת���Ķ�������pRootǰһ������Ľڵ���pPrev
	void _Convert(TreeNode* Root, TreeNode*& pPrev)
	{
		// ����������ת����ֱ�ӷ���
		if (nullptr == Root)
			return;

		// ��pRoot��������ת��Ϊ˫������
		_Convert(Root->left, pPrev);

		// pRoot��leftָ����ǰһ������Ľڵ㣬��pPrev
		// pRoot��right��û�а취�ڱ��εݹ��д�����Ϊ��һ���ڵ㲻֪��
		// �ڱ�����ֻ�ܴ���ǰ�ڵ��left
		Root->left = pPrev;

		// ǰһ���ڵ��rightָ����û�д���rightָ����ָ���һ���ڵ㣬��pRoot
		if (pPrev)
			pPrev->right = Root;

		pPrev = Root;

		// ��pRoot��������ת��Ϊ˫������
		_Convert(Root->right, pPrev);
	}

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
			return nullptr;

		// ��˫������ĵ�һ���ڵ㣬��������С�Ľڵ�
		TreeNode* pHead = pRootOfTree;
		while (pHead->left)
			pHead = pHead->left;

		// ʹ��prev��Ǹո�ת�����Ľڵ�
		TreeNode* prev = nullptr;
		_Convert(pRootOfTree, prev);
		return pHead;
	}
};

