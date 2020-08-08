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
	assert(a);
	int gap = n;
	while(gap>1){
		//ֻ��gap���Ϊ1�����ܱ�֤���������������Ҫ��1
		gap = gap / 3 + 1;
		//����ֻ�ǰѲ��������1����gap����
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

//ѡ������
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
		//��С�ķ�����ǰ��
		Swap(&a[min], &a[begin]);
		//�������λ����beginλ��˵��min�Ǻ����Ľ���λ�����ʱ��max��λ�þͷ����˱任��max�䵽��min��λ��
		//����Ҫ����max��λ��
		if (max == begin)
			max = min;
		Swap(&a[max], &a[end]);
		begin++;
		end--;
	}
}

//������
//���µ�����
void AdjustDwon(int* a, int n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while(child<n){
		//ȡ���Һ��Ӵ��һ��
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

//���Ӷ�Ϊ O(N*LogN)
void HeapSort(int* a, int n)
{
	assert(a);
	// �����򣬽���ѣ������һ���ӽڵ�ĸ���ʼ
	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDwon(a, n, i);
	}

	//���һ��λ��
	int end = n - 1;
	while(end>0){
		//a[0]�������
		Swap(&a[0], &a[end]);
		//���½���
		AdjustDwon(a, end, 0);
		end--;
	}
}

//ð������
void BubbleSort(int* a, int n){
	for (int end = n - 1; end > 0; --end)
	{
		//��һ����ǣ�����м�û�з�������˵��ǰ���ֵ���Ⱥ����С,��������������
		//��õ�����£�����ʱ�临�ӶȾ�ΪO(N)
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

//����ȡ��
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

//����
// hoare��
int HoareMethod(int* a, int begin, int end){
	// end��key��������� 
	//begin��key���ұ�����
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int start = begin;

	while(begin<end){
		//��С
		while (begin < end&&a[end] >= key)
			--end;
		//�Ҵ�
		while (begin < end&&a[begin] <= key)
			++begin;

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[start]);
	return begin;
}

// �ڿӷ� 
int DigHoleMethod(int* a, int begin, int end){
	//begin�ǿ�
	int key = a[begin];
	while (begin < end)
	{
		// ��С
		while (begin < end && a[end] >= key)
			--end;
		a[begin] = a[end]; // �ҵ�С�ķŵ�begin�Ŀ�����ȥ,ͬʱend�γ��µĿ�λ

		while (begin < end && a[begin] <= key)
			++begin;
		a[end] = a[begin]; // �ҵ�С�ŵ�end�Ŀ�����ȥ��ͬʱbegin�γ��µĿ�λ
	}

	a[begin] = key;
	return begin;
}

// ǰ��ָ��汾 
int PrevCurMethod(int* a, int begin, int end){
		int midindex = GetMidIndex(a, begin, end);
		Swap(&a[begin], &a[midindex]);

		int key = a[begin];
		int prev = begin;
		int cur = begin + 1;

		while (cur <= end)
		{
			// cur��С����С����ǰ�����������
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