// write your code here cpp
#include<iostream>
#include<set>
#include<string>

using namespace std;

int main(){
	int n;
	while (cin >> n){
		set<string> st;
		string str;
		for (int i = 0; i < n; i++){
			cin >> str;
			st.insert(str);
		}

		set<string>::iterator it;
		for (it = st.begin(); it != --st.end(); ++it){
			auto next = it++;
			auto pos = (*it).find((*next));
			if ((pos == string::npos) || (pos != 0) || (*it)[(*next).size()] != '/')//�ж��ǲ��Ǻ����������Ӵ������ҿ�ʼλ����ͬ�����������������
				cout << "mkdir -p " << *next << endl;
			it = next;
		}
		cout << "mkdir -p " << *(--st.end()) << endl;//���ۺ���������һ��һ��������
		cout << endl;
	}
	return 0;
}