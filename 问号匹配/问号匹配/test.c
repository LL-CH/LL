bool isMatch(char * s, char * p){
	int len_s = strlen(s);
	int len_p = strlen(p);
	bool **dp = (bool**)malloc((len_s + 1)*sizeof(bool *));
	for (int i = 0; i <= len_s; i++) {
		dp[i] = (bool*)calloc(len_p + 1, sizeof(bool));
	}
	dp[0][0] = true;
	for (int i = 1; i <= len_p; i++) {
		if (p[i - 1] == '*' && dp[0][i - 1])
			dp[0][i] = true;
	}
	for (int i = 1; i <= len_s; i++) {
		for (int j = 1; j <= len_p; j++) {
			if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else if (p[j - 1] == '*') {
				dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
			}
		}
	}
	return dp[len_s][len_p];
}