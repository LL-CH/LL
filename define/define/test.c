#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a)+(b))  //注意加括号,防止因操作符产生的意外

int main(){
	int a = 10;
	int b = 20;
	printf("%d\n", MAX(a, b)*5);
	system("pause");
}