#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main(){
	string s1;
	string s2;
	while (cin >> s1 >> s2){
		//Ҳ������map
		unordered_map<char, int> mapa, mapb;
		//��s1��s2�����ݷ���map��
		for (int i = 0; i < s1.size(); i++){
			mapa[s1[i]]++;
		}
		for (int i = 0; i<s2.size(); i++){
			mapb[s2[i]]++;
		}
		//����һ����־λ���ж��Ƿ����
		bool flag = true;
		//����s2���ж����Ƿ�������������������flag��Ϊflase�����No������ѭ��
		for (unordered_map<char, int>::iterator it = mapb.begin(); it != mapb.end(); it++){
			if (it->second>mapa[it->first]){
				cout << "No" << endl;
				flag = false;
				break;
			}
		}
		if (flag == true)
			cout << "Yes" << endl;
	}
	return 0;
}