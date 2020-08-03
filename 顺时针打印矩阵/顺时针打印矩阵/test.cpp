class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if (matrix.empty())
			return ret;
		//�С���
		int row = matrix.size() - 1; //�ҵ���Ŀ�ʼ��
		int col = matrix[0].size() - 1;//�µ��ϵĿ�ʼ��

		int x = 0;//���ҵĿ�ʼ��
		int y = 0;//�ϵ��µĿ�ʼ��

		while (1){
			//��������
			for (int i = x; i <= col; i++)
				ret.push_back(matrix[x][i]);
			if (++y > row)
				break;
			//��������
			for (int i = y; i <= row; i++)
				ret.push_back(matrix[i][col]);
			if (--col < x)
				break;
			//���ҵ���
			for (int i = col; i >= x; i--)
				ret.push_back(matrix[row][i]);
			if (--row<y)
				break;
			//���µ���
			for (int i = row; i >= y; i--)
				ret.push_back(matrix[i][x]);
			if (++x>col)
				break;
		}
		return ret;
	}
};