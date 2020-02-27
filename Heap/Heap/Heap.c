#include "Heap.h"

// 小堆 
// ->条件：左右子树都是堆
void AdjustDown(HpDataType* a, size_t n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 找出小的那个孩纸
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}

		// 1、孩纸比父亲小，则交换，继续往下调
		// 2、孩纸比父亲大，则终止调整
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

Heap* HeapCreate(HpDataType* a, size_t n)
{
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	hp->_a = malloc(sizeof(HpDataType)*n);
	//hp->_a = a;
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	// 建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}

	return hp;
}

void HeapPush(Heap* hp, HpDataType x)
{

}
void HeapPop(Heap* hp);
HpDataType HeapTop(Heap* hp);