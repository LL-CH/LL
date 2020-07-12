#include<iostream>
#include<string>
#include "RB.h"


using namespace std;

void test(){
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.InOrder();
	cout << t.IsValidRBTRee() << endl;
}

int main(){
	test();
	system("pause");
	return 0;
}