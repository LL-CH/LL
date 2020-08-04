class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.empty() && popped.empty())
			return true;
		if (pushed.size() != popped.size())
			return false;
		stack<int> st;
		int j = 0;
		for (int i = 0; i < pushed.size(); i++){
			//��������ջ
			st.push(pushed[i]);
			//�����ʱstջ����ֵ���ڳ�ս���еĵ�һ�������ͳ�ջ
			//����ͼ�����pushed������ջ��ֱ���ҵ����ջ���е�ǰֵ��ͬ����
			while (!st.empty() && st.top() == popped[j]){
				st.pop();
				j++;
			}
		}
		return st.empty();
	}
};