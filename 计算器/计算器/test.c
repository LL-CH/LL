#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main(){
	float a, b;
	char c;
		printf("输入:");
		scanf("%f%c%f", &a, &c, &b);

		switch (c)
		{
		case '+':printf("%f%c%f=%f\n", a, c, b, a + b);
			break;
		case'-':printf("%f%c%f=%f\n", a, c, b, a - b);
			break;
		case'*':printf("%f%c%f=%f\n", a, c, b, a * b);
			break;
		case'/':
			//除法分母 不能为0
			if (b == 0){
				printf("输入错误!请从新输入!\n");
				break;
			}
			else {
				printf("%f%c%f=%f\n", a, c, b, a / b);
				break;
			}
		default:printf("输入错误!\n");

		
	}
	system("pause");
}