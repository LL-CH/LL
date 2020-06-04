#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢����������� 
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
	//������ת
	reverse(s.begin(), s.end());

	//������ת
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