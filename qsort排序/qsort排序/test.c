#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
	return (*(int*)a - *(int*)b);//���ڷ���1 ���ڷ���0 С�ڷ���-1
}

int main(){
	int arr[] = { 1, 3, 5, 4, 2, 7, 9, 0, 8 };
	//cmp����1���� -1����
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}