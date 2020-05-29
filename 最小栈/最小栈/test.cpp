#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() { }

	void push(int x) {
		_st.push(x);
		if (_minst.empty() || _minst.top() >= x)
		{
			_minst.push(x);
		}
	}

	void pop() {
		if (_st.top() == _minst.top())
			_minst.pop();

		_st.pop();
	}

	int top() {
		return _st.top();
	}

	int getMin() {
		return _minst.top();
	}

	stack<int> _st;
	stack<int> _minst;
};

int main(){
	MinStack  s1;
	s1.push(0);
	s1.push(2);
	s1.push(-1);
	s1.push(0);

	cout<<s1.getMin()<<endl;
	s1.pop();
	s1.pop();
	s1.pop();

	cout << s1.top() << endl;
	system("pause");
}