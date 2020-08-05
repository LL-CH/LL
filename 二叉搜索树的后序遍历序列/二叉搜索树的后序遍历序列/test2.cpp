//�����鷭ת����˳��Ϊ�������󡱣��������ʹ�õ���ջ�洢���ڵ����������
//������������ʱ���������ڵ�϶��ȸ��ڵ��������С�����γ�ջ��������root�ڵ㡣
//���root�ڵ�С�ڼ�����ջ��Ԫ�أ�˵��˳�����ֱ�ӷ���ʧ�ܡ�

//��ע��Ϊ�˱�֤��һ���ڵ���ջʱ����ȷ�ԣ�root�ڵ��ʼ��ΪINT_MAX.


class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.size() == 0){
			return true;
		}
		stack<int> q;
		int root = INT_MAX;
		for (int i = postorder.size() - 1; i >= 0; i--){
			if (postorder[i] > root){
				return false;
			}
			while (!q.empty() && q.top() > postorder[i]){
				root = q.top();
				q.pop();
			}
			q.push(postorder[i]);
		}
		return true;
	}
};