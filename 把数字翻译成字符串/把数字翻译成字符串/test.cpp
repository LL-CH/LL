class Solution {
public:
	int translateNum(int num) {
		string str = to_string(num);
		int n = str.size();
		vector<int> dp(1 + n);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2, j = num; i <= n; i++){
			//判断最后两位的的值大小
			if (9 < j % 100 && j % 100 < 26)
				dp[i] = dp[i - 1] + dp[i - 2];
			else
				dp[i] = dp[i - 1];
			j /= 10;
		}
		return dp[n];
	}
};