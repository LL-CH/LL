
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		if (value % 2 == 1)        // 取数字的二进制序列中的一个 1 
		{
			count++;
		}
		value /= 2;                //减掉所得的一个1
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
