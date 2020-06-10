#include<iostream>
#include<vector>

using namespace std;

//m*n������ ���Ͻǵ����½ǵķ����м��� ��ʵ��Ϊm+1��n+1)
//ֻ�����Һ�����
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