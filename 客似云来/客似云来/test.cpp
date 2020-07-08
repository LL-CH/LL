#include<iostream>

using namespace std;

int main(){
	long long arr[80] = { 1, 1 };
	for (int i = 2; i < 80; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	int from = 0, to = 0;
	while (cin >> from >> to){
		long long res = 0;
		for (int i = from; i <= to; i++){
			res += arr[i - 1];
		}
		cout << res << endl;
	}
	return 0;
}