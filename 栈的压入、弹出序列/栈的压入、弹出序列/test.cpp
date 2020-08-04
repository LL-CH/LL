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
			//将数据入栈
			st.push(pushed[i]);
			//如果此时st栈顶的值等于出战数列的第一个数，就出栈
			//否则就继续将pushed数列入栈，直到找到与出栈序列当前值相同的数
			while (!st.empty() && st.top() == popped[j]){
				st.pop();
				j++;
			}
		}
		return st.empty();
	}
};