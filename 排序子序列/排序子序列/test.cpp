#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	vector<int> num;
	cin >> n;
	num.resize(n);
	for (size_t i = 0; i<n; i++)
	{
		cin >> num[i];
	}

	int ret = 1;
	for (int i = 1; i<n - 1; i++)
	{
		if (num[i]>num[i - 1] && num[i]>num[i + 1] || num[i] < num[i - 1] && num[i] < num[i + 1])
		{
			ret++;
			if (i != n - 3)
			{
				i++;
			}
		}
	}
	cout << ret << endl;
	return 0;
}