#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

int find(int arr[ROW][COL], int n){
	//��ά����  int** arr
	//�����Ͻǵ����ֿ�ʼ�� Ҳ���Դ����½�����ʼ�� (ROW-1,0)
	//ʱ�临�Ӷ� ROW+COL
	int row = 0;
	int col = COL - 1;
	while (1){
		//����,������һ��
		if (arr[row][col] < n){
			row++;
		}
		//С��,�ص���һ��
		if (arr[row][col] > n){
			col--;
		}
		if (arr[row][col] == n){
			printf("�ҵ���!\n");
			printf("����Ϊ:%d %d", row, col);
			break;
		}
		else{
			printf("û�ҵ�!\n");
			break;
		}
	}
	return 0;
}

int main(){
	//��ά���鶯̬����
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
	printf("����Ҫ�ҵ���:");
	scanf("%d", &n);
	find(arr, n);
	system("pause");
	return 0;
}