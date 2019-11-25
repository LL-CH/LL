#include <stdio.h>
#include <stdlib.h>

//比较函数
int int_cmp(const void* p1,const void* p2){
	return (*(int *)p1 - *(int *)p2); 
}

//交换函数
void swap(void *p1, void * p2, int size) {
	int i = 0;
	for (i = 0; i < size; i++) 
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}

//冒泡排序模拟实现qsort
void bubble(void *base, int count, int size, int(*cmp)(void*,void*))
{ 
	int i = 0;
	int j = 0;
	for (i = 0; i< count - 1; i++)
	{ 
		for (j = 0; j<count - i - 1; j++)
	{
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) > 0)
			{ 
				swap((char *)base + j*size, (char *)base + (j + 1)*size, size);
			} 
		} 
	}
} 
int main() {
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	//char *arr[] = {"aaaa","dddd","cccc","bbbb"};
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}