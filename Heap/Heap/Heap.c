#include "Heap.h"
#include<string.h>
#include <malloc.h>

// С�� 
// ->�����������������Ƕ�
void AdjustDown(HpDataType* a, size_t n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		// �ҳ�С���Ǹ���ֽ
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}

		// 1����ֽ�ȸ���С���򽻻����������µ�
		// 2����ֽ�ȸ��״�����ֹ����
		if (a[parent] > a[child])
		{
			HpDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//������һ����
void AdjustUp(int* a, HpDataType child)
{
	while (child > 0)
	{
		HpDataType tmp;
		int parent = (child - 1) / 2;
		if (a[child] < a[parent]){
			tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else{
			break;
		}
	}
}



Heap* HeapCreate(HpDataType* a, size_t n)
{
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	hp->_a = malloc(sizeof(HpDataType)*n);
	//hp->_a = a;
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	// ����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}

	return hp;
}

void HeapPush(Heap* hp, HpDataType x)
{
	if (hp->_size == hp->_capacity){
		HpDataType newcapcity = hp->_capacity * 2;
		hp->_a = (HpDataType*)realloc(sizeof(HpDataType))*newcapcity;
	}
}
void HeapPop(Heap* hp);
HpDataType HeapTop(Heap* hp);