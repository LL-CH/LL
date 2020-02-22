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

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
//输出(打印)
void SListPrint(SListNode* pList);
//尾插
void SListPushBack(SListNode** ppList, SLTDataType x);
//头插
void SListPushFront(SListNode** pList, SLTDataType x);
//尾删
void SListPopBack(SListNode** ppList);
//头删
void SListPopFront(SListNode** pList);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDataType x);
// 单链表在pos位置之后插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos);
//单链表的销毁
void SListDestory(SListNode** pplist);