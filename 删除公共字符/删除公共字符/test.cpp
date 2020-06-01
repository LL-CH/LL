#include<iostream>
#include <string>

using namespace std;

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);

	for (size_t i = 0; i < s1.size(); i++)
	{
		for (size_t j = 0; j < s2.size(); j++)
		{
			if (s2[j] == s1[i])
			{
				s1.erase(i, 1);
			}
		}
	}
	cout << s1 << endl;
	return 0;
}