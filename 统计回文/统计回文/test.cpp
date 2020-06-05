//将s2插入s1的各个位置，判断是否为回文
//统计回文的次数

#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

//判断回文
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
	//各个位置插入s2并判断
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