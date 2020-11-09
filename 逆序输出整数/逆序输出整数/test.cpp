#include<iostream>

using namespace std;

void _reverse(int num){
	if (num == 0)
		return;
	cout << num % 10;
	_reverse(num / 10);
}

int main(){
	int num = 12345;
	_reverse(num);
	system("pause");
	return 0;
}