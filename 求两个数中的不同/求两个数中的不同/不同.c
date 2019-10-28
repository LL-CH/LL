#include<stdio.h>
#include<stdlib.h>

int count_one_bits( int value)         // 取数字的二进制序列中的 1的个数
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
	int result = a^b;    //取异或,相同为0,相异为1
	int count = count_one_bits(result);     //求1的个数即为不同的个数
	printf("二进制序列中不同的个数count = %d\n", count);
	system("pause");
}
