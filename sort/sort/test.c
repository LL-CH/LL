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

void testMergeSort()
{
	int a[] = { 2, 3, 7, 4, 8, 6, 9, 2, 1 };
	MergeSort(a, sizeof(a) / sizeof(int)-1);
	Print(a, sizeof(a) / sizeof(int));
}

void testCountSort()
{
	int a[] = { 3, 4, 6, 2, 8, 5, 2, 2, 9, 9, 1000000, 99999 };
	CountSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

// O(Max(N, ∑∂Œß))
// O(N+∑∂Œß)  ±º‰∏¥‘”∂»
// O(∑∂Œß) ø’º‰∏¥‘”∂»
void TestSortOP()
{
	const int n = 1000000;
	int* a1 = (int*)malloc(sizeof(int)*n);
	int* a2 = (int*)malloc(sizeof(int)*n);
	int* a3 = (int*)malloc(sizeof(int)*n);
	int* a4 = (int*)malloc(sizeof(int)*n);
	int* a5 = (int*)malloc(sizeof(int)*n);
	int* a6 = (int*)malloc(sizeof(int)*n);
	int* a7 = (int*)malloc(sizeof(int)*n);
	int* a8 = (int*)malloc(sizeof(int)*n);

	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}
	a8[n] = 100000000;

	size_t begin1 = clock();
	//InsertSort(a1, n);
	size_t end1 = clock();
	printf("%u\n", end1 - begin1);

	size_t begin2 = clock();
	ShellSort(a2, n);
	size_t end2 = clock();
	printf("%u\n", end2 - begin2);

	size_t begin3 = clock();
	//SelectSort(a3, n);
	size_t end3 = clock();
	printf("%u\n", end3 - begin3);

	size_t begin4 = clock();
	HeapSort(a4, n);
	size_t end4 = clock();
	printf("%u\n", end4 - begin4);

	size_t begin5 = clock();
	//BubbleSort(a5, n);
	size_t end5 = clock();
	printf("%u\n", end5 - begin5);

	size_t begin6 = clock();
	QuickSort(a6, 0, n - 1);
	size_t end6 = clock();
	printf("%u\n", end6 - begin6);

	size_t begin7 = clock();
	MergeSort(a7, n);
	size_t end7 = clock();
	printf("%u\n", end7 - begin7);

	size_t begin8 = clock();
	CountSort(a8, n);
	size_t end8 = clock();
	printf("%u\n", end8 - begin8);
}

int main(){
	//testInsertSort();
	//testShellSort();
	//testSelectSort();
	//testHeapSort();
	//testBubbleSort();
	testQuickSort();
	//testMergeSort();
	//testCountSort();
	system("pause");
	return 0;
}