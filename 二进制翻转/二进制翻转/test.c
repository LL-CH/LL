#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bit(unsigned int value){
	unsigned int a;
	unsigned int b = 0;
	for (int i = 0; i < 32; i++){

		//#include <math.h>
		//b+=((value>>i)&1)*pow(2,31-i);

		a = value & 1;   //ȡ���һλ����
		value=value >> 1;
		b = b + (a << (31 - i)); //����ֵΪ��������ÿһλ��ֵ֮��
	}
	return b;
}

unsigned int reverse_bit2(unsigned int value){
	unsigned int ret = 0;
	//������

	for (int i = 0; i < 32; i++){
		ret <<= 1;
		ret ^= (value >> i) & 1;
		//ret|=(value>>i) & i;
	}
	return ret;
}
int main(){
	unsigned int a;
	scanf("%d", &a);
	printf("%u\n", reverse_bit(a));
	printf("%u\n", reverse_bit2(a));
	system("pause");
}
