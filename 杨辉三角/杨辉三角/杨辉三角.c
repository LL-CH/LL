#include<stdio.h>
#include<stdlib.h>
 
#define N 10          //ʹ�ú궨��������εĸ߶ȶ���,���ڸ���

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
		int arr[N][N] = { 0 };          //����ά����ȫ����ֵΪ0
		Triangle(arr);

		system("pause");
		return 0;
	}

	//��̬��ά����Ľ���
	/*
	#include
	int row;
	sacnf("%d", &row);
	int** arr = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++){
		arr[i] = (int*)malloc(sizeof(int)* (i - 1));
	}*/
	//�ͷ�
	/*for (int i = 0; i < row; i++){
		free(arr[i]);
	}
	free(arr);
	*/