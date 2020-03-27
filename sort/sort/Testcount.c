#include<stdio.h.>
#include<stdlib.h>
#include"sort.h"

// O(Max(N, 范围))
// O(N+范围) 时间复杂度
// O(范围) 空间复杂度
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}
	//找到数据的范围
	int range = max - min + 1;
	int* countArray = (int*)malloc(range*sizeof(int));
	memset(countArray, 0, sizeof(int)*range);
	//存放在相对位置，可以节省空间
	for (int i = 0; i < n; ++i)
	{
		countArray[a[i] - min]++;
	}
	//可能存在重复的数据，有几个存几个
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArray[i]--)
		{
			a[index++] = i + min;
		}
	}
}

void TestCountSort()
{
	int a[] = { 3, 4, 6, 2, 8, 5, 2, 2, 9, 9, 1000000, 99999 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

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