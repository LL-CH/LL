#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void mul(i){
	printf("����������\n");
	scanf("%d", &i);
	int n, m;
	for (n = 1; n <= i; n++)
	{
		for (m = 1; m <= n; m++)
		{
			if (m > n)
				break;
			printf("%d*%d=%-2d", n,m,n*m);
		}
		printf("\n");
	}
}
	int main() {

	int a = 0;
	printf("�˷���:\n", a);
	mul(a);
	system("pause");
}