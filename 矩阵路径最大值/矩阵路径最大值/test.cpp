class Solution {
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	*
	* @param matrix int���Ͷ�ά����
	* @param matrixRowLen int matrix��������
	* @param matrixColLen int* matrix��������
	* @return int����
	*/
	int maxValue(int** matrix, int matrixRowLen, int* matrixColLen) {
		// write code here
		if (matrixRowLen == 0)
			return 0;
		int dp[matrixRowLen][*matrixColLen];
		dp[0][0] = matrix[0][0];
		for (int i = 1; i<matrixRowLen; i++){
			dp[0][i] = dp[0][i - 1] + matrix[0][i];
		}
		for (int i = 1; i<*matrixColLen; i++){
			dp[i][0] = dp[i - 1][0] + matrix[i][0];
		}
		for (int i = 1; i<*matrixColLen; i++){
			for (int j = 1; j<matrixRowLen; j++){
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[matrixRowLen - 1][*matrixColLen - 1];
	}
};

class Solution {
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	*
	* @param matrix int���Ͷ�ά����
	* @param matrixRowLen int matrix��������
	* @param matrixColLen int* matrix��������
	* @return int����
	*/
	int maxValue(int** matrix, int matrixRowLen, int* matrixColLen) {
		// write code here
		if (matrixRowLen == 0)
			return 0;
		int row = matrixRowLen;
		int col = *matrixColLen;
		for (int i = 0; i<row; i++){
			for (int j = 0; j<col; j++){
				int sum1, sum2;
				if (i - 1 >= 0){
					sum1 = matrix[i - 1][j];
				}
				else{
					sum1 = 0;
				}
				if (j - 1 >= 0){
					sum2 = matrix[i][j - 1];
				}
				else{
					sum2 = 0;
				}
				matrix[i][j] += max(sum1, sum2);
			}
		}
		return matrix[row - 1][col - 1];
	}
};