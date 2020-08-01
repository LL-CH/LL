class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> _data;//����ջ
	stack<int> _min;//����ջ
	MinStack() {
	}

	void push(int x) {
		//����ջ��ջ
		_data.push(x);
		//�����ʱ����ջΪ�ջ���xС�ڸ���ջ��ջ��Ԫ�أ���x��ջ�����򽫸���ջ��ջ��Ԫ���ٴ���ջ
		if (_min.size() == 0 || x<_min.top()){
			_min.push(x);
		}
		else{
			_min.push(_min.top());
		}
	}

	void pop() {
		//����ջ����Ϊ�ղ���pop
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
