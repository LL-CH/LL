#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)   //�޷��ű���
{
	int count = 0;
	while (value)
	{
		if (value % 2 == 1)        // ȡ���ֵĶ����������е�һ�� 1 
		{
			count++;
		}
		value /= 2;                //�������õ�һ��1
	}return count;
}//�·������������з��ű���
int count_bit(int value){
	int count = 0;
	
	for (int i = 0; i < 32; i++){
		if (((value >> i) & 1) == 1){
			count++;
		}
	}
		return count;
}


//����
int count_bit2(int n){
	int count = 0;
	while (n){
		n = n&(n - 1);
			count++;
	}
}

int main()
{
	int num = 0;
	/*int count = 0;*/
	printf("������һ������");
	scanf("%d", &num);
	int count = count_one_bits(num);
	/*for (int i = 0; i < 32; i++){
		if (((num >> i) & 1) == 1){
			count++;
		}
	}*/
	int count1 = count_bit(num);
	int count2=count_bit2(num);
	printf("������������1�ĸ���count = %d\n", count1);
	printf("������������1�ĸ���count = %d\n", count2);
	printf("������������1�ĸ���count = %d\n", count);
	system("pause");
	return 0;
}
