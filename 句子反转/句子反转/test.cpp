#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s;
	vector<string> vec;
	while (cin >> s)
		vec.push_back(s);
	for (int i = vec.size() - 1; i >= 0; i--)
		cout << vec[i] << " ";
	cout << endl;
}