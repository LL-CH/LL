//Ҫ��������ָ��ż��������������ֵ��С��������
#include<iostream>

using namespace std;

//�ж�����
bool isPrime(int x){
	for (int i = 2; i < x; i++){
		if (x%i == 0)
			return false;
	}
	return true;
}

int main(){
	int num;
	while (cin >> num){
		int prime1 = num / 2;  //���м俪ʼ��
		int prime2 = num - prime1;
		while (1){
			if (isPrime(prime1) && isPrime(prime2)) //��Ϊ���������
				break;
			prime1--;
			prime2++;
		}
		cout << prime1 << endl;
		cout << prime2 << endl;
	}

	return 0;
}