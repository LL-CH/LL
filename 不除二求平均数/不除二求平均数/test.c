#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a;
	int b;
	scanf("%d %d", &a, &b);
	printf("%d\n", (a + b) >> 1);  //二进制数中右移一位就是除二
	printf("%d\n", (a & b)+((a^b)>> 1));
	system("pause");
	return 0;
}