
#include<stdio.h>
#include<stdlib.h>
void init(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = i;
		printf("%2d", arr[i]);
	}
	
}
void empty(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
		printf("%2d", arr[i]);
	}
	
}
void reverse(int arr[], int size)
{
	int i = 0;
	int left = 0;
	int right = size - 1;
	for (i = 0; i < size; i++)
	{
		while (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
		printf("%2d", arr[i]);
	}
}
int main(){
	int arr[5] = { 1 , 5 , 8 , 9 , 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("逆置数组:\n");
	reverse(arr, size);
	printf("\n");
	printf("初始化数组:\n");
	init(arr,size);
	printf("\n");
	printf("清空数组:\n");
	empty(arr, size);
	printf("\n");
	system("pause");
}