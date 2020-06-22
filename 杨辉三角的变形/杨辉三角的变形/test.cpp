#include<iostream>
#include<vector>

using namespace std;

int Print(int n){
	vector<vector<int>> v(n, vector<int>(2 * n - 1, 0));
	//½«×óÓÒ¶¼ÖÃ1
	v[0][n - 1] = 1;
	v[n - 1][0] = v[n - 1][2 * n - 2] = 1;
	if (n < 2){
		return -1;
	}
	for (int i = 1; i < n; i++){
		for (int j = 1; j < 2 * n - 2; j++){
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
		}
	}
	for (int i = 0; i < 2 * n - 1; i++){
		if ((v[n - 1][i] != 0) && (v[n - 1][i] % 2 == 0)){
			return i + 1;
		}
	}

}

int main(){
	int n;
	while (cin >> n){
		int ret = Print(n);
		cout << ret << endl;
	}
	return 0;
}