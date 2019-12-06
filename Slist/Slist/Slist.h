#pragma once

#include <stdio.h>
#include <malloc.h>

typedef int SLTDataType;
//链表结构体
typedef struct SListNode
{
	SLTDataType data; // val
	struct SListNode* next;
}SListNode;

//输出
void SListPrint(SListNode* pList);
//尾插
void SListPushBack(SListNode** ppList, SLTDataType x);
//头插
void SListPushFront(SListNode** pList, SLTDataType x);
//尾删
void SListPopBack(SListNode** ppList);
//头删
void SListPopFront(SListNode** pList);