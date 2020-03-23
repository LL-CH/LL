#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// С��
typedef int HpDataType;
typedef struct Heap
{
	HpDataType* _a;
	size_t      _size;
	size_t      _capacity;
}Heap;

//���µ�����
void AdjustDown(HpDataType* a, size_t n, int root);
//���ϵ���
void AdjustUp(int* a, int child);

//����
void HeapCreate(Heap* hp, HpDataType* a, size_t n);
//����
void HeapDestory(Heap* hp);
//����
void HeapPush(Heap* hp, HpDataType x);
// ɾ��
void HeapPop(Heap* hp);
//ȡ�Ѷ�����
HpDataType HeapTop(Heap* hp);
//�п�
int HeapEmpty(Heap* hp);
//���
void HeapPrint(Heap* hp);
//������
void HeapSort(int* a, int n);
// topK
void PrintTopK(int* a, int n, int k);