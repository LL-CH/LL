#include<iostream>

using namespace std;

int main(){
	int n;
	while (cin >> n){
		int num = 0;
		for (int i = 2; i*i <= n; i++){
			//�����Ĺ�����
			if (n%i == 0){
				while (n%i == 0){
					n /= i;
				}
				//��һ��������������һ������
				num++;
			}
		}
		//��Ϊ1˵��ֻ�ܱ���������
		if (n != 1)
			num++;
		cout << num << endl;
	}
	return 0;
}