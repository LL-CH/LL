//�����������ַ� ֻ�ܣ� �� ��
//Ҫ�໥��Ӧ

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		if (n % 2 == 1)
			return false;
		stack<char> s;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == '(')
			{
				s.push(A[i]);
			}
			else if (A[i] == ')')
			{
				if (s.empty())
					return false;
				else
					s.pop();
			}
			else
				return false;
		}
		if (s.empty())
			return true;
	}
};

