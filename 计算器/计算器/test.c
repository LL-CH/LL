#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main(){
	float a, b;
	char c;
	printf("����:");
	scanf("%f %c %f", &a, &c, &b);
	switch (c)
	{
		case '+':printf("%f &c &f=%f\n", a, c, b, a + b);
			break;
		case'-':printf("%f &c &f=%f\n", a, c, b, a - b);
			break;
		case'*':printf("%f &c &f=%f\n", a, c, b, a * b);
			break;
		case'/':
			if (b == 0){
				printf("�������!���������!\n");
			}
			else {
				printf("%f &c &f=%f\n", a, c, b, a / b);
				break;
			}
		default:printf("�������!\n");
	
	}
	system("pause");
}