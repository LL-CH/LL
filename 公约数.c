#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
		printf("������������:\n");
		scanf("%d%d", &a, &b);
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
			
		}
		printf("���Լ����:\n");
		printf("%d\n", a);
		
	
	system("pause");
	
}


