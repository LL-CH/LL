#include<stdio.h.>
#include<stdlib.h>
#include"sort.h"

void testInsertSort(){
	int a[] = { 2, 3, 7, 4, 8, 6, 9, 2, 1 };
	InsertSort(a, sizeof(a) / sizeof (int));
	Print(a, sizeof(a) / sizeof (int));
}

void testShellSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void testSelectSort(){
	int a[] = { 2, 3, 7, 4, 8, 6, 9, 2, 1 };
	SelectSort(a, sizeof(a) / sizeof (int));
	Print(a, sizeof(a) / sizeof (int));
}

void testHeapSort()
{
	int a[] = { 2, 3, 7, 4, 8, 6, 9, 2, 1 };
	HeapSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void testBubbleSort()
{
	int a[] = { 2, 3, 7, 4, 8, 6, 9, 2, 1 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void testQuickSort()
{
	int a[] = { 2, 3, 7, 4, 8, 6, 9, 2, 1 };
	QuickSort(a, 0,sizeof(a) / sizeof(int)-1);
	Print(a, sizeof(a) / sizeof(int));
}

int main(){
	//testInsertSort();
	//testShellSort();
	//testSelectSort();
	//testHeapSort();
	//testBubbleSort();
	testQuickSort();

	system("pause");
	return 0;
}