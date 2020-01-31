#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int x){
	int num = x;
	long res = 0;//ÊıÖµÒç³ö
	while (x > 0){
		res = res * 10 + x % 10;
		x = x / 10;
	}
	if (res == num){
		return 1;
	}
	else
		return 0;
}

int main(){
	int x = 123;
	int res = isPalindrome(x);
	printf("%d\n", res);
	system("pause");
}