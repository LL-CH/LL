//ʹ�õݹ���n�Ľ׳�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Fac(int n){
	if (n <= 1){
		return 1;
	}
	return n *  Fac(n - 1);
}
int main(){
	int n = 0;
	printf("����n����ֵ:");
	scanf("%d", &n);
	int result = Fac(n);
	printf("n�Ľ׳�Ϊ:%d\n", result);
	system("pause");
}
//�ǵݹ�ʵ��n�Ľ׳�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Fac(int n){
	int result = 1;
	while (n > 1){
		result *= n;
		n--;
	}
	return result;
}
int main(){
	int n = 0;
	printf("����n����ֵ:");
	scanf("%d", &n);
	int result = Fac(n);
	printf("n�Ľ׳�Ϊ:%d\n", result);
	system("pause");
}