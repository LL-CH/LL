#include<iostream>

using namespace std;

int main(){
	long long a[100001] = { 1, 2 };
	//ȡ쳲�����������λ
	for (int i = 2; i<100001; i++)
		a[i] = (a[i - 2] + a[i - 1]) % 1000000;
	int n;
	while (cin >> n){
		//�����жϣ���ʱ������ֵ����100000�ķֽ紦
		if (n>28)
			printf("%06d\n", a[n - 1]);
		else
			cout << a[n - 1] << endl;
	}
	return 0;
}