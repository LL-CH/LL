
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		if (value % 2 == 1)        // ȡ���ֵĶ����������е�һ�� 1 
		{
			count++;
		}
		value /= 2;                //�������õ�һ��1
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
