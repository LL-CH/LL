#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(){
	char a[100];
	while (scanf("%s", a) != EOF){
		int n = strlen(a);
		for (int i = 0; i<n - 1; i++){
			for (int j = n - 1; j>i; j--){
				if (a[j]<a[j - 1]){
					int tmp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmp;
				}
			}
		}
		for (int k = 0; k<n; k++){
			printf("%c", a[k]);
		}
	}
	return 0;
}