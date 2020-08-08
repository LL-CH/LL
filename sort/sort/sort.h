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
	assert(a);
	int gap = n;
	while(gap>1){
		//只有gap最后为1，才能保证最后有序所以这里要加1
		gap = gap / 3 + 1;
		//这里只是把插入排序的1换成gap即可
		for (int i = 0; i < n - gap;i++){
			int end = i;
			int tmp = a[end + gap];
			while(end>=0 && a[end]>tmp){
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int *p2){
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序
void SelectSort(int* a, int n){
	assert(a);
	int begin = 0;
	int end = n - 1;
	while(begin<end){
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end;i++){
			if (a[i]>a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
		}
		//最小的放在最前面
		Swap(&a[min], &a[begin]);
		//如果最大的位置在begin位置说明min是和最大的交换位置这个时候max的位置就发生了变换，max变到了min的位置
		//所以要更新max的位置
		if (max == begin)
			max = min;
		Swap(&a[max], &a[end]);
		begin++;
		end--;
	}
}

//堆排序
//向下调整法
void AdjustDwon(int* a, int n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while(child<n){
		//取左右孩子大的一个
		if (child + 1 < n&&a[child + 1] > a[child])
			child++;
		if(a[child]>a[parent]){
			Swap(&a[child],&a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

//复杂度为 O(N*LogN)
void HeapSort(int* a, int n)
{
	assert(a);
	// 排升序，建大堆，从最后一个子节点的根开始
	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDwon(a, n, i);
	}

	//最后一个位置
	int end = n - 1;
	while(end>0){
		//a[0]是最大数
		Swap(&a[0], &a[end]);
		//从新建堆
		AdjustDwon(a, end, 0);
		end--;
	}
}

//冒泡排序
void BubbleSort(int* a, int n){
	for (int end = n - 1; end > 0; --end)
	{
		//加一个标记，如果中间没有发生交换说明前面的值都比后面的小,即本身就是有序的
		//最好的情况下，它的时间复杂度就为O(N)
		int flag = 0;
		for (int i = 0; i < end; ++i)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
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
	if(a[mid]>a[begin]){
		if (a[mid] < a[end])
			return mid;
		else if (a[begin]>a[end])
			return begin;
		else
			return end;
	}
	// begin >= mid
	else{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] > a[end])
			return end;
		else
			return begin;
	}
}

//快排
// hoare法
int HoareMethod(int* a, int begin, int end){
	// end做key，左边先走 
	//begin做key，右边先走
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int start = begin;

	while(begin<end){
		//找小
		while (begin < end&&a[end] >= key)
			--end;
		//找大
		while (begin < end&&a[begin] <= key)
			++begin;

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[start]);
	return begin;
}

// 挖坑法 
int DigHoleMethod(int* a, int begin, int end){
	//begin是坑
	int key = a[begin];
	while (begin < end)
	{
		// 找小
		while (begin < end && a[end] >= key)
			--end;
		a[begin] = a[end]; // 找到小的放到begin的坑里面去,同时end形成新的坑位

		while (begin < end && a[begin] <= key)
			++begin;
		a[end] = a[begin]; // 找到小放到end的坑里面去，同时begin形成新的坑位
	}

	a[begin] = key;
	return begin;
}

// 前后指针版本 
int PrevCurMethod(int* a, int begin, int end){
		int midindex = GetMidIndex(a, begin, end);
		Swap(&a[begin], &a[midindex]);

		int key = a[begin];
		int prev = begin;
		int cur = begin + 1;

		while (cur <= end)
		{
			// cur找小，把小的往前翻，大的往后翻
			if (a[cur] < key && ++prev != cur)
				Swap(&a[cur], &a[prev]);

			++cur;
		}

		Swap(&a[begin], &a[prev]);

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