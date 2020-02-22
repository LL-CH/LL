#include "SList.h"

//��ӡ
void SListPrint(SListNode* pList)
{
	SListNode* cur = pList;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

	printf("NULL\n");
}

//��̬����һ���ڵ�
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

//β��
void SListPushBack(SListNode** ppList, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);

	if (*ppList == NULL)
	{
		*ppList = newNode;
	}
	else
	{
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}
}

//ͷ��
void SListPushFront(SListNode** ppList, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}

//βɾ
void SListPopBack(SListNode** ppList)
{
	// 1.��
	// 2.ֻ��һ���ڵ�
	// 3.�ж���ڵ�
	if (*ppList == NULL)
	{
		return;
	}
	else if ((*ppList)->next == NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		if (prev != NULL)
			prev->next = NULL;
	}
}

//ͷɾ
void SListPopFront(SListNode** ppList){
	if (*ppList == NULL)
	{
		return;
	}
	//else if ((*ppList)->next == NULL)
	//{
	//	free(*ppList);
	//	*ppList = NULL;
	//}
	else
	{
		SListNode* cur = *ppList;
		SListNode* next = cur->next;
		*ppList = next;
		free(cur);
	}
}

// ����
SListNode* SListFind(SListNode* pList, SLTDataType x)
{
	SListNode* cur = pList;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}

	return NULL;
}

//pos������x
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	/*SListNode* newnode = BuySListNode(x);
	SListNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;*/

	SListNode* newnode = BuySListNode(x);
	pos->next = newnode;
	newnode->next = pos->next;
}

//ɾ��pos
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;
	if (next != NULL)
	{
		pos->next = next->next;
		free(next);
	}
}

//����
void SListDestory(SListNode** pplist)
{
	SListNode* cur = *pplist;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pplist = NULL;
}