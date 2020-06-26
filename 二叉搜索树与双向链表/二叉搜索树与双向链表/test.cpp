/*
思路：
1. 空树直接返回
2. 非空
a. 在二叉搜索树中找到链表的首节点
b. 要转化为有序的链表，二叉搜索树中序遍历刚好可以得到一个有序序列，因此采用中序遍历的规则进行转化，在转化过程中，只需要改变每个节点左右指针域的指向即可。
具体实现：参考代码
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
	// pPrev标记刚刚转化的节点，pRoot表示现在要转化的二叉树，pRoot前一个处理的节点是pPrev
	void _Convert(TreeNode* Root, TreeNode*& pPrev)
	{
		// 空树：不用转化，直接返回
		if (nullptr == Root)
			return;

		// 将pRoot的左子树转化为双向链表
		_Convert(Root->left, pPrev);

		// pRoot的left指向其前一个处理的节点，即pPrev
		// pRoot的right域没有办法在本次递归中处理，因为下一个节点不知道
		// 在本次中只能处理当前节点的left
		Root->left = pPrev;

		// 前一个节点的right指针域没有处理，right指针域指向后一个节点，即pRoot
		if (pPrev)
			pPrev->right = Root;

		pPrev = Root;

		// 将pRoot的右子树转化为双向链表
		_Convert(Root->right, pPrev);
	}

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
			return nullptr;

		// 找双向链表的第一个节点，即树中最小的节点
		TreeNode* pHead = pRootOfTree;
		while (pHead->left)
			pHead = pHead->left;

		// 使用prev标记刚刚转化过的节点
		TreeNode* prev = nullptr;
		_Convert(pRootOfTree, prev);
		return pHead;
	}
};

