#pragma once
#include "stack.h"
#include<string.h>


void Print(int* a, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������
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

//ϣ������
void ShellSort(int* a, int n){
	//gap>1  Ԥ����
	//gap=1  ��������
	int gap = n;
	while (gap > 1){
		//���gap��Ԥ����
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

//ѡ������
void SelectSort(int* a, int n){
	int begin = 0, end = n - 1;
	while (begin < end){
		//[begin,end]�����Сֵ�±�
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

//������
//���µ�����
void AdjustDwon(int* a, int n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		// ѡ�����Һ����д����һ��
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		// ������ӱȸ��״��򽻻����������µ���
		// �������С�ڸ��ף����������
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

//���Ӷ�Ϊ O(N*LogN)
void HeapSort(int* a, int n)
{
	// �����򣬽����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0){
		// �ѶѶ���ǰ�����һ�λ������
		swap(&a[0], &a[end]);
		// ����ѡ��ʣ�µ����������
		AdjustDwon(a, end, 0);
		--end;
	}
}

//ð������
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

//����ȡ��
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

//����
// hoare��
int HoareMethod(int* a, int begin, int end){
	// end��key��������� 
	//begin��key���ұ�����
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		// begin�Ҵ�
		while (begin < end && a[begin] <= key)
			++begin;

		// end��С
		while (begin < end && a[end] >= key)
			--end;

		swap(&a[begin], &a[end]);
	}

	swap(&a[begin], &a[keyindex]);
	return begin;
}

// �ڿӷ� 
int DigHoleMethod(int* a, int begin, int end){
	int key = a[end];
	while (begin < end)
	{
		// �Ҵ�
		while (begin < end && a[begin] <= key)
			++begin;
		a[end] = a[begin]; // �ҵ���ŵ��ұߵĿ�����ȥ,ͬʱend�γ��µĿ�λ

		while (begin < end && a[end] >= key)
			--end;
		a[begin] = a[end]; // �ҵ�С�ŵ���ߵĿ�����ȥ��ͬʱbegin�γ��µĿ�λ
	}

	a[begin] = key;
	return begin;
}

// ǰ��ָ��汾 
int PrevCurMethod(int* a, int begin, int end){
	//��������ʱ
	//int midindex = GetMidIndex(a, begin, end);
	//Swap(&a[midindex], &a[end]);

	int prev = begin - 1;
	int cur = begin;
	int key = a[end];

	while (cur < end) // ����key��λ�þͽ�����
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

//�ǵݹ�
void QuickSortNonr(int *a, int begin, int end){
	//��һ��ջʵ��
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

//�鲢
void Merge(int *a, int begin, int end,int *tmp){
	if (begin >= end)
		return;
	//����
	int mid = (begin + end) / 2;
	Merge(a, begin, mid,tmp);
	Merge(a, mid + 1, end,tmp);
	//�鲢
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

	// ���鲢��tmp�����ݹ鲢��Ԫ����
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}


//�鲢����
void MergeSort(int *a, int n){
	int *tmp = (int *)malloc(sizeof(int)*n);
	Merge(a, 0, n - 1, tmp);
	free(tmp);
}

//��������
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
	//�ҵ����ݵķ�Χ
	int range = max - min + 1;
	int* countArray = (int*)malloc(range*sizeof(int));
	memset(countArray, 0, sizeof(int)*range);
	//��������λ�ã����Խ�ʡ�ռ�
	for (int i = 0; i < n; ++i)
	{
		countArray[a[i] - min]++;
	}
	//���ܴ����ظ������ݣ��м����漸��
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