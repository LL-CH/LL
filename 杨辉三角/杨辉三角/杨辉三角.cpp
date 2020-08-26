#include<iostream>
#include<stdlib.h>
#include<vector>
 
#define N 10          //使用宏定义对三角形的高度定义,便于更改

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		// 先开辟杨辉三角的空间
		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; ++i)
		{
			vv[i - 1].resize(i, 0);
			// 每一行的第一个和最后一个都是1
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


void Triangle(int arr[N][N])          //将三角形的表示用二维数组代替
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col <= row; col++)
		{
			 arr[row][0] = 1;                  //每一行的第一位值都为1
			if (row >= 1 && col >= 1)
			{
				arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];     //每一个数都等于其上一行前一列数和上一行本列数之和
				
			}
			printf(" %d ", arr[row][col]);
		}
		printf("\n");
	}
}

	int main(){
		//int arr[N][N] = { 0 };          //将二维数组全都赋值为0
		//Triangle(arr);
		system("pause");
		return 0;
	}
