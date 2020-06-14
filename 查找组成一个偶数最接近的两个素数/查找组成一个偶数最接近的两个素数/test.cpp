//要求输出组成指定偶数的两个素数差值最小的素数对
#include<iostream>

using namespace std;

//判断素数
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
		int prime1 = num / 2;  //从中间开始找
		int prime2 = num - prime1;
		while (1){
			if (isPrime(prime1) && isPrime(prime2)) //都为素数则输出
				break;
			prime1--;
			prime2++;
		}
		cout << prime1 << endl;
		cout << prime2 << endl;
	}

	return 0;
}