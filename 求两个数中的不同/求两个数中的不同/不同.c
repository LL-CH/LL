#include<stdio.h>
#include<stdlib.h>

int count_one_bits( int value)         // ȡ���ֵĶ����������е� 1�ĸ���
{
	int count = 0;

	for (int i = 0; i < 32; i++){
		if (((value >> i) & 1) == 1){
			count++;
		}
	}
	return count;
}

int main()
{
	int a = 1999;
	int b = 2299;
	int result = a^b;    //ȡ���,��ͬΪ0,����Ϊ1
	int count = count_one_bits(result);     //��1�ĸ�����Ϊ��ͬ�ĸ���
	printf("�����������в�ͬ�ĸ���count = %d\n", count);
	system("pause");
}
