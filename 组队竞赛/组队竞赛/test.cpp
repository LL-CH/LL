#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	vector <int> num;
	cin >> n;
	num.resize(3 * n);
	for (int i = 0; i < 3 * n; i++)
	{
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	//intµÄ·¶Î§²»¹»ÓÃ
	long long sum = 0;
	for (int i = n; i < 3 * n; i += 2)
	{
		sum += num[i];
	}
	cout << sum << endl;
	return 0;
}