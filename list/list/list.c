#include "list.h"
#include <stdio.h>

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListDestroy(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	//ListNode* newnode = BuyListNode(x);
	// phead tail newnode
	//ListNode* tail = pHead->prev;
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = pHead;
	//pHead->prev = newnode;
	ListInsert(pHead, x);
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	//ListNode* newnode = BuyListNode(x);
	//ListNode* first = pHead->next;
	//pHead->next = newnode;
	//newnode->prev = pHead;
	//newnode->next = first;
	//first->prev = newnode;
	/*ListNode* newNode = BuyListNode(x);
	newNode->next = pHead->next;
	pHead->next->prev = newNode;
	pHead->next = newNode;
	newNode->prev = pHead;*/
	ListInsert(pHead->next, x);
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	//ListNode* tail = pHead->prev;
	//ListNode* tailPrev = tail->prev;
	// pHead tailPrev tail
	//tailPrev->next = pHead;
	//pHead->prev = tailPrev;
	//free(tail);
	/*ListNode* tail = pHead->prev;
	pHead->prev = tail->prev;
	tail->prev->next = pHead;
	free(tail);*/
	ListErase(pHead->prev);
}

void ListPopFront(ListNode* pHead)
{
	ListErase(pHead->next);
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	// prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
��������������������������������
��Ȩ����������ΪCSDN�������� @ţ����ԭ�����£���ѭ CC 4.0 BY - SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https ://blog.csdn.net/weixin_45667134/article/details/104450719