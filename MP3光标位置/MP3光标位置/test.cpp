#include<iostream>
#include<string>

using namespace std;

int main(){
	int n; //��������
	string order; //����
	while (cin >> n >> order){
		int pos = 1;//�����±�
		int page = 1;//ҳ��

		if (n <= 4){
			for (int i = 0; i < order.size(); i++){
				if (pos == 1 && order[i] == 'U')//��ͷ��β
					pos = n;
				else if (pos == n && order[i] == 'D')//��β��ͷ
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
				if (pos == 1 && order[i] == 'U' && page == 1){//��ͷ��β
					pos = n;
					page = n - 3;
				}
				else if (pos == n && order[i] == 'D' && page == n - 3){
					//��β��ͷ
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