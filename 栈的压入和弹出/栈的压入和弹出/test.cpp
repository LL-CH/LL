class Solution{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV){
		//入栈和出栈的元素个数必须相同
		if (pushV.size() != popV.size())
			return false;

		// 用s来模拟入栈与出栈的过程
		int outIdx = 0;
		int inIdx = 0;
		stack<int> s;
		while (outIdx < popV.size()){	

			// 如果s是空，或者栈顶元素与出栈的元素不相等，就入栈
			while (s.empty() || s.top() != popV[outIdx]){
				if (inIdx < pushV.size())
					s.push(pushV[inIdx++]);
				else
					return false;
			}

			// 栈顶元素与出栈的元素相等，出栈
			s.pop();
			outIdx++;
		}
		return true;
	}
};