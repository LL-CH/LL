#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s, ret;
	while (getline(cin, s)){
		getline(cin, ret);
		bool flag = false;
		for (int i = 0; i < s.length(); i++)
		{
			string t;
			if (s[i] == '"')
			{
				i++;
				while (i < s.length() && s[i] != '"')
				{
					t += s[i];
					i++;
				}
				if (t == ret)
				{
					flag = true;
					break;
				}
			}
			else if (s[i] != ',')
			{
				while (i < s.length() && s[i] != ',')
				{
					t += s[i];
					i++;
				}
				if (t == ret)
				{
					flag = true;
					break;
				}
			}
		}
		if (flag == true)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}