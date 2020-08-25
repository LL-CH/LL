/*�����������*/
/*
ʹ�ú�������ķ�ʽ������������ÿ���ڵ㣬��ô�ڱ�����һ���ڵ�֮ǰ���Ǿ��Ѿ�
��������������������ֻҪ��ÿ���ڵ��ʱ���¼�������(ĳһ�ڵ����ȵ�������Ҷ�ڵ��·���ĳ��ȣ�
�Ϳ����ж�ÿ���ڵ��ǲ���ƽ���
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