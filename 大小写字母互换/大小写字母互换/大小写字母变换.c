#include<stdio.h>
#include<stdlib.h>

//字符串大写字母转为小写字母
char * tolowercase(char * str){

	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z'){
			str[i] = str[i] + 32;
		}
	}
	return str;
}

int main()
{
	printf("输入一个字符:\n");
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

