
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	int j=0;
	for (i = 1; i < 8; i++)
	{
		j = 2 * i - 1;
		for (j; j>0; j--)
		{
			printf("*");
		}
		printf("\n");
		printf("\n");
	}
	for (i = 6; i > 0; i--)
	{
		j = 2 * i - 1;
		for (j; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
		printf("\n");
	}


	int i;
	int max;
	scanf("%d", &max);
	for (i = 1; i <= max; i++){
		int j;
		for (j = 1; j <= 2 * i - 1; j++){
			printf(" ");
		}
		printf("\n");

	}
	for (i = 1; i <= max; i++){
		int j;
		for (j = 1; j <= 2 *(max- i) - 1; j++){
			printf(" ");
		}
		printf("\n");

	}
	system("pause");
	return 0;
}
