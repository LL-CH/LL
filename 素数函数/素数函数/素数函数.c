#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int prime_number(int n){
	int  m;
	scanf("%d", &n);
	if (n < 2){
		printf("%d不是素数\n");
	}
	else {
		for (m = 2; m < n; m++){  //m<=sqrt(n)   n的开方数
			if (n%m == 0){
				break;
			}
		}
		if (m >= n){
			printf("是素数!\n");
		}
		else {
			printf("不是素数!\n");
		}
	}return 0;
}
int main(){
	printf("输入一个数：\n");
	int num = 0;
	prime_number(num);
	system("pause");
}