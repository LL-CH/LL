#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int DigitSum(int n){
	if (n < 0) {    //为负数时返回0
		return 0;
	}
	 if (n < 10){   //个位数返回本身
		return n;
	}
	 return n % 10 + DigitSum(n / 10);    //取每一位的数字相加
}
int main(){
	printf("输入一个数：\n");
	int n ;
	scanf("%d", &n);
	int sum= DigitSum(n);
	printf("%d\n", sum);
	system("pause");
}

