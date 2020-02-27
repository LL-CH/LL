#pragma once
#include <stdio.h>

typedef int HpDataType;
typedef struct Heap
{
	HpDataType* _a;
	size_t      _size;
	size_t      _capacity;
}Heap;

Heap* HeapCreate(HpDataType* a, size_t n);

void HeapPush(Heap* hp, HpDataType x);

void HeapPop(Heap* hp);

HpDataType HeapTop(Heap* hp);

// topK