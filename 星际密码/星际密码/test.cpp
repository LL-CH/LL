#include<iostream>
#include<vector>

using namespace std;

int main(){
	const int Max = 10005; //��󲻳���10000
	vector<int>  v = { 1, 1, 2 };
	//쳲�����
	//��ÿ��λ�ö�Ӧ�����������
	for (int i = 3; i < Max; i++){
		v.push_back((v[i - 1] + v[i - 2]) % 10000);
	}

	int n;
	int num;
	while (cin >> n){
		while (n--){
			cin >> num;
			//�����Ӧλ�õ���λ��
			printf("%04d", v[num]);
		}
		printf("\n");
	}
	return 0;
}