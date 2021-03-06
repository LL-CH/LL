#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)   //无符号变量
{
	int count = 0;
	while (value)
	{
		if (value % 2 == 1)        // 取数字的二进制序列中的一个 1 
		{
			count++;
		}
		value /= 2;                //减掉所得的一个1
	}return count;
}//下方代码适用于有符号变量
int count_bit(int value){
	int count = 0;
	
	for (int i = 0; i < 32; i++){
		if (((value >> i) & 1) == 1){
			count++;
		}
	}
		return count;
}


//或者
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
	printf("请输入一个数：");
	scanf("%d", &num);
	int count = count_one_bits(num);
	/*for (int i = 0; i < 32; i++){
		if (((num >> i) & 1) == 1){
			count++;
		}
	}*/
	int count1 = count_bit(num);
	int count2=count_bit2(num);
	printf("二进制序列中1的个数count = %d\n", count1);
	printf("二进制序列中1的个数count = %d\n", count2);
	printf("二进制序列中1的个数count = %d\n", count);
	system("pause");
	return 0;
}
