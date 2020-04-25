#include <stdio.h>
#include <stdlib.h>
int fib(int n){
	if (n <= 2){
		return 1;
	}
	return fib(n - 1) + fib(n - 2);

}

int con(int a){
	int count = 0;
	for (int i = 0; i < 50; i++){
		if (a = fib(i)){
			return count;;
		}
		else{
			a++;
			count++;
		}
	}
	return count;
}


int main(){
	int n = con(5);
	printf("%d\n", n);
	system("pause");
}