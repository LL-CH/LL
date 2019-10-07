#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void change(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
int main() {
	int a = 0;
	int b = 0;
	printf("输入两个数a和b:\n");
	scanf("%d %d", &a, &b);
	change(&a, &b);
	printf("a=%d,b=%d \n", a, b);
	system("pause");
	
}
