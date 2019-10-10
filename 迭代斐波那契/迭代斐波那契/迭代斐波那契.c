#include <stdio.h>
#include <stdlib.h>
int fib(int n){
	if (n <= 2){
		return 1;
	}
	return fib(n - 1) + fib(n - 2);

}
int main(){
	int n = fib(5);
	printf("%d\n", n);
	system("pause");
}