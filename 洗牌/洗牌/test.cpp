#include<iostream>
#include<vector>

using namespace std;

int main(){
	int t, n, k;
	cin >> t;
	while (t--){
		cin >> n >> k;
		int num = 2 * n;
		vector<int> v(num);
		for (int i = 0; i < num; i++){
			cin >> v[i];
		}

		while (k--){
			vector<int> v1(v.begin(), v.end());
			for (int i = 0; i < n; i++){
				v[2 * i] = v1[i];
				v[2 * i + 1] = v1[i + n];
			}
		}

		for (int i = 0; i < num - 1; i++){
			cout << v[i] << " ";
		}
		cout << v[num - 1] << endl;
	}
	return 0;
}