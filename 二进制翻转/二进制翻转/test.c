#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bit(unsigned int value){
	int a;
	int b=0;
	for (int i = 0; i < 32; i++){
		a = value & 1;
		value=value >> 1;
		b = b + (a << (31 - i));
	}
	return b;
}

int main(){
	int a;
	scanf("%d", &a);
	printf("%u\n", reverse_bit(a));
	system("pause");
}