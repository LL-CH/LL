#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int A, B;
	int i = 1;
	scanf("%d %d", &A, &B);
	for (i = 1; i <= A*B; i++){
		if (i%A == 0 && i%B == 0){
			printf("%d\n", i);
			break;
		}
		
	}
	system("pause");
	return 0;
}