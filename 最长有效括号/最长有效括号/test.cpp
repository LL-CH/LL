
//��ջģ��һ�飬�������޷�ƥ������ŵ�λ��ȫ����1
//����: "()(()"��markΪ[0, 0, 1, 0, 0]
//������: ")()((())"��markΪ[1, 0, 0, 1, 0, 0, 0, 0]
//���������Ĵ����, ����ͱ����Ѱ�����������0�ĳ���class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		vector<bool> mark(s.length());
		for (int i = 0; i < s.size(); i++) {
			mark[i] = 0;
		}
		int left = 0, len = 0, ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				st.push(i);
			else {
				// ������������ǲ���Ҫ�ģ����
				if (st.empty())
					mark[i] = 1;
				else
					st.pop();
			}
		}
		// δƥ����������ǲ���Ҫ�ģ����
		while (!st.empty()) {
			mark[st.top()] = 1;
			st.pop();
		}
		// Ѱ�ұ������֮�����󳤶�
		for (int i = 0; i < s.size(); i++) {
			if (mark[i]) {
				len = 0;
				continue;
			}
			len++;
			ans = max(ans, len);
		}
		return ans;
	}
};