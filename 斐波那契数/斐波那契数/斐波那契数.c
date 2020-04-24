//∑«µ›πÈ µœ÷
#include <stdio.h>
#include <stdlib.h>
int fib(int n){
	
	if (n < 2) {
		return n;
	}
		int last2 = 0;
		int last1 = 1;
		int result = 0;
		for (int i = 2; i <= n; i++){
			result = (last1 + last2) % 1000000007;
			last2 = last1;
			last1 = result;
		}
		return result;
}

int fib2(int n){
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int a = 0, b = 1, sum = 0;
	for (int i = 2; i <= n; i++)
	{
		sum = (a + b) % 1000000007;
		a = b;
		b = sum;
	}
	return sum;
}


int main(){
	printf("%d\n", fib2(45));
	printf("%d\n", fib(45));
	system("pause");
}