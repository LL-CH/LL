//一维数组动规
class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();

		vector<int> dp(col, 0);
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (j == 0)
					dp[0] += grid[i][0];
				else
					dp[j] = grid[i][j] + max(dp[j - 1], dp[j]);
			}
		}
		return dp[col - 1];
	}
};