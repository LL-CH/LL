#include<iostream>
#include<vector>

using namespace std;

//m*n的棋盘 左上角到右下角的方法有几种 （实际为m+1和n+1)
//只能向右和向下
int main()
{
	int m, n;

	while (cin >> m >> n)
	{
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));
		for (int i = 1; i < m + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
		cout << dp[m][n] << endl;
	}
	return 0;
}