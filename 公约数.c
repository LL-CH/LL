#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
		printf("输入两个数字:\n");
		scanf("%d%d", &a, &b);
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
			
		}
		printf("最大公约数是:\n");
		printf("%d\n", a);
		
	
	system("pause");
	
}


