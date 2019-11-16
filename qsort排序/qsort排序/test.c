#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
	return (*(int*)a - *(int*)b);//大于返回1 等于返回0 小于返回-1
}

int main(){
	int arr[] = { 1, 3, 5, 4, 2, 7, 9, 0, 8 };
	//cmp返回1升序 -1降序
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}