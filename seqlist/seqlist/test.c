#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

void test(){
	SeqList s;
	SeqListInit(&s);
	//SeqListPushFront(&s, 1);
	//SeqListPopFront(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPrint(&s);
	//SeqListPopBack(&s);
}

int main(){
	test();
	system("pause");
	return 0;
}