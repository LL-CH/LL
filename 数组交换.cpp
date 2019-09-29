
#include <stdio.h>
#include <stdlib.h>
int exchange(int arr1[], int arr2[], int size){   //定义一个交换数值的函数//
	int i = 0;

	for (i = 0; i <= size; i++){

		int num = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = num;

	}
	return 0;
}

int main()
{
	int i = 0;
	int arr1[10] = { 1, 2, 3, 6, 5, 4, 8, 7, 9, 8 };
	int arr2[10] = { 9, 8, 5, 4, 7, 6, 1, 2, 0, 3 };
	exchange(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]));    //代入函数//
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++){
		printf("%d", arr1[i]);
	
	}printf("\n");
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++){
		printf("%d", arr2[i]);

	}printf("\n");
	system("pause");

}

