//��s2����s1�ĸ���λ�ã��ж��Ƿ�Ϊ����
//ͳ�ƻ��ĵĴ���

#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

//�жϻ���
bool is_reverse(string& s)
{
	if (s.size() == 1)
		return true;
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		if (s[start++] != s[end--])
			return false;
	}
	return true;
}

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int count = 0;
	//����λ�ò���s2���ж�
	for (size_t i = 0; i <= s1.size(); i++)
	{
		string res = s1;
		res.insert(i, s2);
		if (is_reverse(res))
		{
			count++;
		}
	}
	cout << count;
	return 0;
}