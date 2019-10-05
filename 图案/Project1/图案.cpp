
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
	}
	for (i = 6; i > 0; i--)
	{
		j = 2 * i - 1;
		for (j; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
