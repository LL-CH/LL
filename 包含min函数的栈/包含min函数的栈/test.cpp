class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> _data;//数据栈
	stack<int> _min;//辅助栈
	MinStack() {
	}

	void push(int x) {
		//数据栈入栈
		_data.push(x);
		//如果此时辅助栈为空或者x小于辅助栈的栈顶元素，则将x入栈，否则将辅助栈的栈顶元素再次入栈
		if (_min.size() == 0 || x<_min.top()){
			_min.push(x);
		}
		else{
			_min.push(_min.top());
		}
	}

	void pop() {
		//两个栈都不为空才能pop
		assert(_data.size()>0 && _min.size() > 0);
		_data.pop();
		_min.pop();
	}

	int top() {
		return _data.top();
	}

	int min() {
		return _min.top();
	}
};
