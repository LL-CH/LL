#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a;
	int b;
	scanf("%d %d", &a, &b);
	printf("%d\n", (a + b) >> 1);  //��������������һλ���ǳ���
	printf("%d\n", (a & b)+((a^b)>> 1));
	system("pause");
	return 0;
}