#pragma once
#include "stack.h"
#include<string.h>


void Print(int* a, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
void InsertSort(int* a, int n){
	for (int i = 0; i < n - 1; i++){
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0){
			if (a[end]>tmp){
				a[end + 1] = a[end];
				--end;
			}
			else{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int* a, int n){
	//gap>1  预排序
	//gap=1  插入排序
	int gap = n;
	while (gap > 1){
		//间隔gap的预排序
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++){
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0){
				if (a[end]>tmp){
					a[end + gap] = a[end];
					end -= gap;
				}
				else{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void swap(int* p1, int *p2){
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序
void SelectSort(int* a, int n){
	int begin = 0, end = n - 1;
	while (begin < end){
		//[begin,end]最大最小值下标
		int min = begin;
		int max = end;
		for (int i = begin; i <= end; i++){
			if (a[i]>a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
		}
		swap(&a[begin], &a[min]);

		if (begin == max)

		if (begin = max)

			max = min;
		swap(&a[end], &a[max]);
		begin++;
		end--;

	}
}

//堆排序
//向下调整法
void AdjustDwon(int* a, int n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出左右孩子中大的那一个
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		// 如果孩子比父亲大，则交换，继续向下调整
		// 如果孩子小于父亲，则调整结束
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//复杂度为 O(N*LogN)
void HeapSort(int* a, int n)
{
	// 排升序，建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0){
		// 把堆顶当前最大数一次换到最后
		swap(&a[0], &a[end]);
		// 调堆选出剩下的数当中最大
		AdjustDwon(a, end, 0);
		--end;
	}
}

//冒泡排序
void BubbleSort(int* a, int n){
	for (int end = n - 1; end > 0; --end)
	{
		int flag = 0;
		for (int i = 0; i < end; ++i)
		{
			if (a[i] > a[i + 1])
			{
				swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

//三数取中
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;
	// begin mid end
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] < a[end]) // a[mid] > a[end]
			return end;
		else
			return begin;
	}
	else // a[begin] > a[mid]
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end]) // a[mid] < a[end]
			return begin;
		else
			return end;
	}
}

//快排
// hoare法
int HoareMethod(int* a, int begin, int end){
	// end做key，左边先走 
	//begin做key，右边先走
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		// begin找大
		while (begin < end && a[begin] <= key)
			++begin;

		// end找小
		while (begin < end && a[end] >= key)
			--end;

		swap(&a[begin], &a[end]);
	}

	swap(&a[begin], &a[keyindex]);
	return begin;
}

// 挖坑法 
int DigHoleMethod(int* a, int begin, int end){
	int key = a[end];
	while (begin < end)
	{
		// 找大
		while (begin < end && a[begin] <= key)
			++begin;
		a[end] = a[begin]; // 找到大放到右边的坑里面去,同时end形成新的坑位

		while (begin < end && a[end] >= key)
			--end;
		a[begin] = a[end]; // 找到小放到左边的坑里面去，同时begin形成新的坑位
	}

	a[begin] = key;
	return begin;
}

// 前后指针版本 
int PrevCurMethod(int* a, int begin, int end){
	//数组有序时
	//int midindex = GetMidIndex(a, begin, end);
	//Swap(&a[midindex], &a[end]);

	int prev = begin - 1;
	int cur = begin;
	int key = a[end];

	while (cur < end) // 遇到key的位置就结束了
	{
		if (a[cur] < key && ++prev != cur)
			swap(&a[prev], &a[cur]);
		++cur;
	}
	++prev;
	swap(&a[prev], &a[end]);

	return prev;
}

void QuickSort(int* a, int begin, int end){
	if (begin >= end)
		return;
	//int keyindex = HoareMethod(a, begin, end);
	//int keyindex = DigHoleMethod(a, begin, end);
	int keyindex = PrevCurMethod(a, begin, end);

	// [begin, keyindex-1]  key  [keyindex+1,end]
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
}

//非递归
void QuickSortNonr(int *a, int begin, int end){
	//开一个栈实现
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st)){
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);
		int keyindex = PrevCurMethod(a, left, right);
		// [left, keyindex-1]  keyindex  [keyindex+1,right]
		if (left < keyindex - 1){
			StackPush(&st, left);
			StackPush(&st, keyindex - 1);
		}
		if (right > keyindex + 1){
			StackPush(&st, keyindex + 1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}

//归并
void Merge(int *a, int begin, int end,int *tmp){
	if (begin >= end)
		return;
	//划分
	int mid = (begin + end) / 2;
	Merge(a, begin, mid,tmp);
	Merge(a, mid + 1, end,tmp);
	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	if (begin1 <= end1)
	{
		while (begin1 <= end1)
			tmp[index++] = a[begin1++];
	}
	else
	{
		while (begin2 <= end2)
			tmp[index++] = a[begin2++];
	}

	// 将归并到tmp的数据归并回元数组
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}


//归并排序
void MergeSort(int *a, int n){
	int *tmp = (int *)malloc(sizeof(int)*n);
	Merge(a, 0, n - 1, tmp);
	free(tmp);
}

//计数排序
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
			a[index] = i + min;
			index++;
		}
	}
}