#include <iostream>     //Å£¿ÎÍøÁ·Ï°Ìâ
#include <algorithm>

using namespace std;

int x[1002], n;
long long ans;
long long sum, mul;
void dfs(int index)
{
	for (int i = index; i<n; i++)
	{
		sum += x[i];
		mul *= x[i];
		if (sum>mul)
		{
			ans++;
			dfs(i + 1);
		}
		else if (x[i] == 1)
		{
			dfs(i + 1);
		}
		else
		{
			sum -= x[i];
			mul /= x[i];
			break;
		}
		sum -= x[i];
		mul /= x[i];
		for (; i < n - 1 && x[i] == x[i + 1]; i++);
	}
}
int main()
{
	while (cin >> n)
	{
		ans = 0;
		sum = 0;
		mul = 1;
		for (int i = 0; i < n; i++)
			cin >> x[i];
		sort(x, x + n);
		dfs(0);
		cout << ans;
	}
	return 0;
}