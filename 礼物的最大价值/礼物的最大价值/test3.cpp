//原数组动规
class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (i == 0 && j >= 1)
					grid[i][j] += grid[i][j - 1];
				if (j == 0 && i >= 1)
					grid[i][j] += grid[i - 1][j];
				else if (j >= 1 && i >= 1)
					grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
			}
		}
		return grid[m - 1][n - 1];
	}
};