#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int power (int n, int k){
	if (k == 1){
		return n;
	}
	return n*power(n, k - 1);

}

int main(){
	printf(" ‰»Î£∫\n");
	int n, k;
	scanf("%d %d", &n, &k);
	int result= power(n, k);
	printf("%d\n", result);
	system("pause");
}
