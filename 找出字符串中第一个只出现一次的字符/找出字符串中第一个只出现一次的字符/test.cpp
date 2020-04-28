#include<iostream>
#include<string>
using namespace std;

int firstUniqChar(string s) {
	// 统计每个字符出现的次数
	int count[256] = { 0 };
	int size = s.size();
	for (int i = 0; i < size; ++i)
		count[s[i]] += 1;
	// 按照字符次序从前往后找只出现一次的字符
	for (int i = 0; i < size; ++i)
	if (1 == count[s[i]])
		return i;

	return -1;
}

int main(){
	string str;
	while (getline(cin, str))
	{
		int res = firstUniqChar(str);
		if (res == -1)
			cout << -1 << endl;
		else
			cout << str[res] << endl;
	}
	return 0;
}