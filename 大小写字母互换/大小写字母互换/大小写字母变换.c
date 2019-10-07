#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("ÊäÈëÒ»¸ö×Ö·û:\n");
	int input = 0;	
	while ((input = getchar()) != EOF)	
	{
		if (input >= 'a' && input <= 'z')
		{
			putchar(input - 32);
		}
		else if (input>= 'A' && input <= 'Z')
		{
			putchar(input + 32);
		}
		else if (input >= '0' && input <= '9')
		{
			continue;	
		}
	}
	system("pause");

}

