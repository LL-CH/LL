#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num ;
	int i = 0;
	int sn = 0, product = 0;
	printf("输入一个数num:");
	scanf("%d", &num);
	for (i = 1; i < 6; i++){
		product = num * 10 + num;
		sn += product;
		num = num * 10;
	}printf("结果为:%d\n", sn);

	

	system("pause");
}
