#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int num;
	while (cin >> num){
		int count = 0;
		int maxn = 0;
		while (num){
			if (1 & num){   //当前位为1
				count++;
				maxn = max(count, maxn);
			}
			else{
				count = 0;
			}
			num = num >> 1;  //右移一位继续
		}
		cout << maxn << endl;
	}
	return 0;
}