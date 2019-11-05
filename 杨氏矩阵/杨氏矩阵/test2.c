#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

int find(int arr[ROW][COL], int n){
	int row = 0;
	int col = COL - 1;
	while (1){
		if (arr[row][col] < n){
			row++;
		}
		if (arr[row][col] > n){
			col--;
		}
		if (arr[row][col] == n){
			printf("找到了!\n");
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
	int arr[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = 10;
	find(arr, n);
	system("pause");
	return 0;
}