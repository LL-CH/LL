#include<iostream>
#include<string>
#include<unordered_map>
#include <unordered_set>

using namespace std;

int main(){
	//n������,m���ֶ�
	int n, m;
	//��¼�������ֳ��ֵĴ���
	unordered_map<string, int> _map;
	cin >> n >> m;
	//�洢���룬��set�����ظ�
	unordered_set<string> phone;
	string str;
	//���������phone��
	while(n--){
		cin >> str;
		if(str.size()!=11)
			continue;
		phone.insert(str);
	}

	unordered_set<string>::iterator it = phone.begin();
	for (it; it != phone.end();it++){
		str = *it;
		unordered_set<string> _char;
		////��һ���ֻ��������е�������Ϸ�ʽ���д洢���ÿռ��滻ʱ��
		for (int i = 0; i < 11;i++){
			string tmp;
			for (int j = i; j < 11;j++){
				tmp += str[j];
				_char.insert(tmp);
			}
		}
		//����
		for(auto e : _char){
			_map[e]++;
		}
	}
	while(m--){
		cin >> str;
		cout << _map[str] << endl;
	}

	return 0;
}