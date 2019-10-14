#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int bin_search(int arr[], int left, int right, int num){
	int mid = 0;
	while (left <= right){
		mid = (left + right) / 2;
		if (arr[mid] > num){
			right = mid - 1;
		}
		else if (arr[mid] < num){
			left = mid + 1;
		}
		else {
			return mid;//�����±�//
		}
	}
	return -1;//û�ҵ�,����-1//
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = (sizeof(arr) / sizeof(arr[0])) - 1;
	int num = 0;
	printf("�����������:\n");
	scanf("%d", &num);
	int result = bin_search(arr,left,right,num );
	printf("result=%d\n", result);
	system("pause");
}

