
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool issame(TreeNode* A, TreeNode* B){
		//BΪ�գ�˵��������
		if (B == nullptr)
			return true;
		//AΪ�գ�˵��A��ûB
		if (A == nullptr)
			return false;
		//ֵ����ͬ��˵���ڵ㲻ͬ
		if (A->val != B->val)
			return false;
		//�Ƚ����������Ƿ���ͬ
		return issame(A->left, B->left)
			&& issame(A->right, B->right);
	}

	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr)
			return false;
		bool res = false;
		//�ҵ���ʼλ��
		if (A->val == B->val)
			//�Ӹ���ʼλ�ÿ�ʼ�������Ƿ�һ��
			res = issame(A, B);
		//��һ�£���A����������ʹ����ͬ�ķ�ʽ����
		if (!res)
			res = isSubStructure(A->left, B);
		//����һ�£�ȥ������
		if (!res)
			res = isSubStructure(A->right, B);

		return res;
	}
};