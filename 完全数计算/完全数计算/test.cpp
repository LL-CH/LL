#include<iostream>   //Å£¿Î £¨»ªÎªOJ£©

using namespace std;

int count(int n){
	int sum = 0;
	for (int i = 1; i < n; i++){
		if (n % i == 0){
			sum += i;
		}
	}
	if (sum == n)
		return 1;
	else
		return 0;
}

int main(){
	int num;
	while (cin >> num){
		int n = 0;
		for (int i = 1; i < num; i++){
			n += count(i);
		}
		cout << n << endl;
	}
	return 0;
}