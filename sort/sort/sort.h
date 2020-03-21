#pragma once

void Print(int* a, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

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
<<<<<<< HEAD
		if (begin == max)
=======
		if (begin = max)
>>>>>>> 4c8a086056ba229c8a41a49dcbb48650f6ac80c0
			max = min;
		swap(&a[end], &a[max]);
		begin++;
		end--;
<<<<<<< HEAD
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
=======
>>>>>>> 4c8a086056ba229c8a41a49dcbb48650f6ac80c0
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