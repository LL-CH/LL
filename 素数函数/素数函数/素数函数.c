#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int prime_number(int n){
	int  m;
	scanf("%d", &n);
	if (n < 2){
		printf("%d��������\n");
	}
	else {
		for (m = 2; m < n; m++){  //m<=sqrt(n)   n�Ŀ�����
			if (n%m == 0){
				break;
			}
		}
		if (m >= n){
			printf("������!\n");
		}
		else {
			printf("��������!\n");
		}
	}return 0;
}
int main(){
	printf("����һ������\n");
	int num = 0;
	prime_number(num);
	system("pause");
}