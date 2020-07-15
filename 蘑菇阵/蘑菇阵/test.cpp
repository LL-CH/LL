#include<iostream>
#include<vector>

using namespace std;

int main(){
	int N, M, K;
	while (cin >> N >> M >> K){
		vector<vector<float>> input(N + 1, vector<float>(M + 1, 0));
		int x, y;
		for (int i = 0; i < K; ++i){
			cin >> x >> y;
			input[x][y] = -1;      //-1±íÊ¾ÓÐÄ¢¹½
		}
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= M; ++j){
				if (i == 1 && j == 1) input[1][1] = 1;
				else if (input[i][j] != -1){
					if (i != N && j != M)
						input[i][j] = input[i - 1][j] * 0.5 + input[i][j - 1] * 0.5;
					if (i == N && j != M)
						input[i][j] = input[i - 1][j] * 0.5 + input[i][j - 1];
					if (i != N && j == M)
						input[i][j] = input[i - 1][j] + input[i][j - 1] * 0.5;
					if (i == N && j == M)
						input[i][j] = input[i - 1][j] + input[i][j - 1];
				}
				else input[i][j] = 0;
			}
		}
		printf("%.2f\n", input[N][M]);
	}
	return 0;
}