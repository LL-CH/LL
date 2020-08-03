class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if (matrix.empty())
			return ret;
		//行、列
		int row = matrix.size() - 1; //右到左的开始行
		int col = matrix[0].size() - 1;//下到上的开始列

		int x = 0;//左到右的开始行
		int y = 0;//上到下的开始列

		while (1){
			//从左往右
			for (int i = x; i <= col; i++)
				ret.push_back(matrix[x][i]);
			if (++y > row)
				break;
			//从上往下
			for (int i = y; i <= row; i++)
				ret.push_back(matrix[i][col]);
			if (--col < x)
				break;
			//从右到左
			for (int i = col; i >= x; i--)
				ret.push_back(matrix[row][i]);
			if (--row<y)
				break;
			//从下到上
			for (int i = row; i >= y; i--)
				ret.push_back(matrix[i][x]);
			if (++x>col)
				break;
		}
		return ret;
	}
};