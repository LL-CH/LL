#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string s;
	string table = "0123456789ABCDEF";
	int i, j;
	cin >> i >> j;

	while (i)
	{
		if (i < 0)
		{
			i = -i;
			cout << '-';
		}
		s += table[i%j];
		i /= j;
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	system("pause");
	return 0;
}