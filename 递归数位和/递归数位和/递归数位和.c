#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int DigitSum(int n){
	if (n < 0) {    //Ϊ����ʱ����0
		return 0;
	}
	 if (n < 10){   //��λ�����ر���
		return n;
	}
	 return n % 10 + DigitSum(n / 10);    //ȡÿһλ���������
}
int main(){
	printf("����һ������\n");
	int n ;
	scanf("%d", &n);
	int sum= DigitSum(n);
	printf("%d\n", sum);
	system("pause");
}

