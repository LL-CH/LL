#include<stdio.h>

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
		if (begin = max)
			max = min;
		swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}