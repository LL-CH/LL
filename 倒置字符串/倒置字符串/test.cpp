#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出 
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2 << endl;
//	return 0;
//}


int main()
{
	string s;
	getline(cin, s);
	//整体逆转
	reverse(s.begin(), s.end());

	//单词逆转
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);

		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	return 0;
}