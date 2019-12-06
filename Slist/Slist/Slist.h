#pragma once

#include <stdio.h>
#include <malloc.h>

typedef int SLTDataType;
//����ṹ��
typedef struct SListNode
{
	SLTDataType data; // val
	struct SListNode* next;
}SListNode;

//���
void SListPrint(SListNode* pList);
//β��
void SListPushBack(SListNode** ppList, SLTDataType x);
//ͷ��
void SListPushFront(SListNode** pList, SLTDataType x);
//βɾ
void SListPopBack(SListNode** ppList);
//ͷɾ
void SListPopFront(SListNode** pList);