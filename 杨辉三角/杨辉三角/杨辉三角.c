#include<stdio.h>
#include<stdlib.h>
 
#define N 10          //使用宏定义对三角形的高度定义,便于更改

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
		int arr[N][N] = { 0 };          //将二维数组全都赋值为0
		Triangle(arr);

		system("pause");
		return 0;
	}

	//动态二维数组的建立
	/*
	#include
	int row;
	sacnf("%d", &row);
	int** arr = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++){
		arr[i] = (int*)malloc(sizeof(int)* (i - 1));
	}*/
	//释放
	/*for (int i = 0; i < row; i++){
		free(arr[i]);
	}
	free(arr);
	*/