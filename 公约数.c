#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	int min,i;
		printf("输入两个数字:\n");
		scanf("%d%d", &a, &b);
		min = a;
		for (i = min; i > 0; i--){
			if (a%i == 0 && b%i == 0){
				printf("最大公约数是:\n",i);
				break;
			}return 1;
		}
		/*	while (a != b)
			{
			if (a > b)
			a = a - b;
			else
			b = b - a;

			}
			printf("最大公约数是:\n");
			printf("%d\n", a);

			*/
	/*	residual = a%b;        //碾转相除法
		while (residual){
			a = b;
			b = residual;
			residual = a%b;
		}
		printf("最大公约数是:\n",b);
		return 0;*/
	system("pause");
	
}


