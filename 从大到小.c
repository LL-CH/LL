#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(){
	int a = 0, b = 0, c = 0;
	int n = 0;
	printf("����������:\n");
	scanf("%d %d %d", &a, &b, &c);
	if (a < b){
		n = b;
		b = a;
		a = n;
		}
	if (a < c){
		n = c;
		c = a;
		a = n;
	}
	if (b < c){
		n = c;
		c = b;
		b = n;
	}
	printf("���ֵΪ:\n");
	printf("%d %d %d\n", a, b, c);
	system("pause");
}

