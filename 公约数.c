#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	int min,i;
		printf("������������:\n");
		scanf("%d%d", &a, &b);
		min = a;
		for (i = min; i > 0; i--){
			if (a%i == 0 && b%i == 0){
				printf("���Լ����:\n",i);
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
			printf("���Լ����:\n");
			printf("%d\n", a);

			*/
	/*	residual = a%b;        //��ת�����
		while (residual){
			a = b;
			b = residual;
			residual = a%b;
		}
		printf("���Լ����:\n",b);
		return 0;*/
	system("pause");
	
}


