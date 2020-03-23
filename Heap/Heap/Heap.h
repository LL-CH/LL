#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 小堆
typedef int HpDataType;
typedef struct Heap
{
	HpDataType* _a;
	size_t      _size;
	size_t      _capacity;
}Heap;

//向下调整法
void AdjustDown(HpDataType* a, size_t n, int root);
//向上调整
void AdjustUp(int* a, int child);

//建堆
void HeapCreate(Heap* hp, HpDataType* a, size_t n);
//销毁
void HeapDestory(Heap* hp);
//插入
void HeapPush(Heap* hp, HpDataType x);
// 删除
void HeapPop(Heap* hp);
//取堆顶数据
HpDataType HeapTop(Heap* hp);
//判空
int HeapEmpty(Heap* hp);
//输出
void HeapPrint(Heap* hp);
//堆排序
void HeapSort(int* a, int n);
// topK
void PrintTopK(int* a, int n, int k);