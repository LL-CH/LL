#include<iostream>
#include<string>

using namespace std;

int main(){
	string s1, s2;
	while (cin >> s1 >> s2){
		if (s1.size() > s2.size())
			swap(s1, s2); //�ҵ��̵���һ��

		string ret; //������
		for (int i = 0; i < s1.size(); i++){
			for (int j = i; j < s1.size(); j++){
				string str = s1.substr(i, j - i + 1);

				if (int(s2.find(str))<0){   //��s2�в����Ƿ���str
					break;
				}
				else{
					if (str.size()>ret.size()) //���½��
						ret = str;
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}