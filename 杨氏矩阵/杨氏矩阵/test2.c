#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

int find(int arr[ROW][COL], int n){
	//二维数组  int** arr
	//从右上角的数字开始找 也可以从左下角数开始找 (ROW-1,0)
	//时间复杂度 ROW+COL
	int row = 0;
	int col = COL - 1;
	while (1){
		//大了,进入下一行
		if (arr[row][col] < n){
			row++;
		}
		//小了,回到上一列
		if (arr[row][col] > n){
			col--;
		}
		if (arr[row][col] == n){
			printf("找到了!\n");
			printf("坐标为:%d %d", row, col);
			break;
		}
		else{
			printf("没找到!\n");
			break;
		}
	}
	return 0;
}

int main(){
	//二维数组动态创建
	/*int row=ROW;
	int col=COL;
	int** arr = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; i++){
		arr[i] = (int*)malloc(sizeof(int)*col);
		for (int j = 0; j < col; j++){
			scanf("%d", &arr[row][col]);
		}
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
*/
	int arr[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = 0;
	printf("输入要找的数:");
	scanf("%d", &n);
	find(arr, n);
	system("pause");
	return 0;
}