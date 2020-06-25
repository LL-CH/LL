#include<iostream>
#include<string>

using namespace std;

int main(){
	int n; //歌曲数量
	string order; //命令
	while (cin >> n >> order){
		int pos = 1;//歌曲下标
		int page = 1;//页号

		if (n <= 4){
			for (int i = 0; i < order.size(); i++){
				if (pos == 1 && order[i] == 'U')//从头到尾
					pos = n;
				else if (pos == n && order[i] == 'D')//从尾到头
					pos = 1;
				else if (order[i] == 'U')
					pos--;
				else
					pos++;
			}
			for (int i = 1; i < n; i++){
				cout << i << ' ';
			}
			cout << n << endl;
			cout << pos << endl;

		}
		else{
			for (int i = 0; i < order.size(); i++){
				if (pos == 1 && order[i] == 'U' && page == 1){//从头到尾
					pos = n;
					page = n - 3;
				}
				else if (pos == n && order[i] == 'D' && page == n - 3){
					//从尾到头
					pos = 1;
					page = 1;
				}
				else if (pos == page && order[i] == 'U' && page != 1){
					pos--;
					page--;
				}
				else if (pos == page + 3 && order[i] == 'D' && page != n - 3){
					pos++;
					page++;
				}
				else if (order[i] == 'U')
					pos--;
				else
					pos++;
			}

			for (int i = page; i < page + 3; i++){
				cout << i << ' ';
			}
			cout << page + 3 << endl;
			cout << pos << endl;
		}
	}
	return 0;
}