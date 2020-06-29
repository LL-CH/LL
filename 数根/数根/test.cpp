#include<iostream>
#include<string>

using namespace std;
//È¡Êý¸ù
int fun(int n){
	int sum = 0;
	while (n){
		sum += n % 10;
		n /= 10;
	}
	while (sum > 9){
		return fun(sum);
	}
	return sum;
}

int main(){
	string n;
	while (cin >> n){
		int num = 0;
		for (size_t i = 0; i < n.size(); i++){
			num += n[i] - '0';
		}
		cout << fun(num) << endl;
	}
	return 0;
}