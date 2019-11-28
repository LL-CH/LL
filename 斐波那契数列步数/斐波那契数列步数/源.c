#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int f1 = 0, f2 = 1, f3;
	int n;
	scanf("%d", &n);
	while (f2 < n){
		f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
	}
	int count1 = abs(n - f1);
	int count2 = abs(f2 - n);
	if (count1>count2){
		printf("%d", count2);
	}
	else{
		printf("%d", count1);
	}
	system("pause");
	return 0;
}