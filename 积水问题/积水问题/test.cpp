#include<iostream>
#include<vector>

using namespace std;

int main(){
	int W, L;
	int num;
	int sum = 0;
	while (cin >> W >> L){
		vector<int> vec(L,0);

		int key = -1;
		for (int i = 0; i < L; i++){
			cin >> num;
			vec[i] = num;
		}

		while (key < L - 1){
			//找到最小值
			int m = key;
			int n = 110;
			for (int i = m + 1; i < L; i++){
				if (vec[i] <= n){
					n = vec[i];
					key = i;
				}
			}
			for (int i = m + 1; i < key; i++){
				int tmp = (vec[i] - n)*W;
				sum += tmp;
			}
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}