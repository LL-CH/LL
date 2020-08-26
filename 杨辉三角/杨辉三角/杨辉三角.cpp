#include<iostream>
#include<stdlib.h>
#include<vector>
 
#define N 10          //ʹ�ú궨��������εĸ߶ȶ���,���ڸ���

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		// �ȿ���������ǵĿռ�
		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; ++i)
		{
			vv[i - 1].resize(i, 0);
			// ÿһ�еĵ�һ�������һ������1
			vv[i - 1][0] = 1;
			vv[i - 1][i - 1] = 1;
		}
		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;
	}
};


void Triangle(int arr[N][N])          //�������εı�ʾ�ö�ά�������
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col <= row; col++)
		{
			 arr[row][0] = 1;                  //ÿһ�еĵ�һλֵ��Ϊ1
			if (row >= 1 && col >= 1)
			{
				arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];     //ÿһ��������������һ��ǰһ��������һ�б�����֮��
				
			}
			printf(" %d ", arr[row][col]);
		}
		printf("\n");
	}
}

	int main(){
		//int arr[N][N] = { 0 };          //����ά����ȫ����ֵΪ0
		//Triangle(arr);
		system("pause");
		return 0;
	}
