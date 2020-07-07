#include<iostream>

using namespace std;

int main(){
	long long a[100001] = { 1, 2 };
	//取斐波那契数后六位
	for (int i = 2; i<100001; i++)
		a[i] = (a[i - 2] + a[i - 1]) % 1000000;
	int n;
	while (cin >> n){
		//加上判断，此时的数列值就是100000的分界处
		if (n>28)
			printf("%06d\n", a[n - 1]);
		else
			cout << a[n - 1] << endl;
	}
	return 0;
}