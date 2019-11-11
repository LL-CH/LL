#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void find(int* arr, int sz){
	int num = 0;
	int ret1 = 0;
	int ret2 = 0;
	int index = 0;
	//��������ͬ�����������
	for (int i = 0; i < sz; i++){
		 num ^= arr[i];   //��� ��ͬΪ0�෴Ϊ1 ��������������һ������,��num����,��ֻ��һ��,���Ϊ�Ǹ���
	}
	//�ҵ���������1��λ��
	for (int i = 0; i < 32; i++){
		if (((num >> i) & 1) == 1){
			index = i;
			break;
		}
	}
	//�ж������д�λ��Ϊ1����
	for (int i = 0; i < sz; i++){
		//��λ��Ϊ1�Ľ������
		if (((arr[i] >> index) & 1) == 1){
			ret1 ^= arr[i];
		}
		//��Ϊ1�Ľ������
		else{
			ret2 ^= arr[i];
		}
	}
	//������
	printf("%d %d\n", ret1, ret2);
}

int main(){
	int n;
	scanf("%d\n", &n);
	int* arr=(int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	find(arr, n);
	system("pause");
	return 0;
}