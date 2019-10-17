#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void parity(int num)
{
	int i  = 0;
	//偶数位输出
	printf("偶数位数列为: ");
	for (i = 0; i < 32; i += 2){               //通过字节的移动得到每一位的数值
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
	//奇数位输出
	printf("奇数位数列为: ");
	for (i = 1; i < 32; i += 2){
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
}
int main()
{
	int num = 0;
	printf("请输入一个数：");
	scanf("%d", &num);
	parity(num);
	
	system("pause");
}