#include<iostream>

using namespace std;

int main(){
	int n;
	while (cin >> n){
		int num = 0;
		for (int i = 2; i*i <= n; i++){
			//找它的公倍数
			if (n%i == 0){
				while (n%i == 0){
					n /= i;
				}
				//有一个公倍数，就有一个因子
				num++;
			}
		}
		//不为1说明只能被自身整除
		if (n != 1)
			num++;
		cout << num << endl;
	}
	return 0;
}