#include<iostream>

using namespace std;

class A	//����
{
public:
	int a;	//�����е�a
	A(int x){ 
		a = x; 
	}
	virtual void Print1() {
		cout << "����1��" << a << endl;
	}

};

class B : public A  //������
{
public:
	int a;   //�������е�ͬ��a
	B(int x,int y) :A(x){ 
		a = y; 
	}
	virtual void Print1(){ 
		cout << "������1��" << a << endl; 
	}
};

void Test(A& p){
	p.Print1();
}

int main(){
	A p1(1);
	B p2(3,10);

	//Test(p1);
	//Test(p2);
	cout << sizeof(p1) << endl;
	system("pause");
	return 0;
}