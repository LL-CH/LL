#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string res;
	int len = 0;
	int pos = 0;

	int start = 0;
	int end = 0;
	while (end < s.size())
	{
		if (s[end]<'0' || s[end]>'9')
		{
			++end;
			start = end;
		}
		else
		{
			++end;
			if ((end - start)>len)
			{
				pos = start;
				len = end - start;
			}
		}
	}

	res = s.substr(pos, len);
	cout << res;
	return 0;
}