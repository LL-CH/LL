
//#include <stdio.h>
//#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
int fib(int n){
	
	if (n == 1 || n == 2) {
		return 1;
	}
		int last2 = 1;
		int last1 = 1;
		int result = 0;
		for (int i = 2; i < n; i++){
			result = last1 + last2;
			last2 = last1;
			last1 = result;
		}
		return result;
}
int main(){
	
	printf("%d\n", fib(40));
	system("pause");
}