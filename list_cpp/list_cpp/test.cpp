#include <iostream>
#include<assert.h>

using namespace std;

#include "list.h"
using namespace LL;

void test_list1()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	for (auto a : l1)
	{
		cout << a << " ";
	}
	cout << endl;
}

void print_list(const list<int>& lt)
{
	list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	print_list(lt);

	lt.pop_back();
	lt.pop_front();
	print_list(lt);

	lt.clear();
	lt.push_back(10);
}

void test_list3()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);

	list<int> lt2(lt1);
	print_list(lt2);

	list<int> lt3;
	lt3.push_back(10);
	lt3.push_back(20);
	lt3.push_back(30);
	lt3.push_back(40);
	lt1 = lt3;
	print_list(lt1);
}

int main(){
	//test_list1();
	//test_list2();
	test_list3();
	system("pause");
}
