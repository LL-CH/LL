#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void print(int n){
	if (n > 9){
		print(n / 10); 
	}
	printf("%d ", n % 10);
}
int main(){
	int num = 0;
	printf ("输入一个数:");
	scanf("%d", &num);
	print (num);
	system("pause");
}
