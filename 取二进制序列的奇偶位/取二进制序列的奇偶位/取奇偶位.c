#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void parity(int num)
{
	int i  = 0;
	//ż��λ���
	printf("ż��λ����Ϊ: ");
	for (i = 0; i < 32; i += 2){               //ͨ���ֽڵ��ƶ��õ�ÿһλ����ֵ
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
	//����λ���
	printf("����λ����Ϊ: ");
	for (i = 1; i < 32; i += 2){
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
}
int main()
{
	int num = 0;
	printf("������һ������");
	scanf("%d", &num);
	parity(num);
	
	system("pause");
}