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
			return mid;//返回下标//
		}
	}
	return -1;//没找到,返回-1//
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	int result = bin_search(arr,0,9,4 );
	printf("result=%d\n", result);
	system("pause");
}

