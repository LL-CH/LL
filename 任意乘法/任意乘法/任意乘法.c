#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int mul(int i){
	printf("输入行数：\n");
	scanf("%d", &i);
	int n, m;
	for (n = 1; n <= i; n++)
	{
		for (m = 1; m <= n; m++)
		{
			if (m > n)
				break;
			printf("%d*%d=%-4d", n,m,n*m);
		}
		printf("\n");
	}return 0;
}
	int main() {

	int a = 0;
	printf("乘法表:\n", a);
	mul(a);
	system("pause");
}