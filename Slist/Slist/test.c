#include "sList.h"
#include<stdlib.h>

void TestSList1()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	SListPrint(pList);

	SListPushFront(&pList, 0);
	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	//SListPopBack(&pList);
	SListPrint(pList);
	SListPopFront(&pList);
	SListPrint(pList);
}

int main()
{
	TestSList1();
	system("pause");
	return 0;
}