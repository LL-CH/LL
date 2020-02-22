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

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
//���(��ӡ)
void SListPrint(SListNode* pList);
//β��
void SListPushBack(SListNode** ppList, SLTDataType x);
//ͷ��
void SListPushFront(SListNode** pList, SLTDataType x);
//βɾ
void SListPopBack(SListNode** ppList);
//ͷɾ
void SListPopFront(SListNode** pList);
// ���������
SListNode* SListFind(SListNode* plist, SLTDataType x);
// ��������posλ��֮�����
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos);
//�����������
void SListDestory(SListNode** pplist);