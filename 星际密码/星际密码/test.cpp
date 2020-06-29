#include<iostream>
#include<vector>

using namespace std;

int main(){
	const int Max = 10005; //最大不超过10000
	vector<int>  v = { 1, 1, 2 };
	//斐波那契
	//将每个位置对应的数计算出来
	for (int i = 3; i < Max; i++){
		v.push_back((v[i - 1] + v[i - 2]) % 10000);
	}

	int n;
	int num;
	while (cin >> n){
		while (n--){
			cin >> num;
			//输出对应位置的四位数
			printf("%04d", v[num]);
		}
		printf("\n");
	}
	return 0;
}