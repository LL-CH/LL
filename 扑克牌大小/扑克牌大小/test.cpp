#include<iostream>  //ţ�Σ���ΪOJ��
#include<string>
#include<algorithm>

using namespace std;

int countCards(string s){
	//��һ�������ַ��������ĸ�������1 2 joker����3
	int res = 0;
	for (unsigned i = 0; i < s.size();)
	{
		while (s[i++] != ' '&&i < s.size());
		res++;
	}
	return res;
}

int main(){
	string str;
	while (getline(cin, str)){
		//�������ը��ֱ�����
		if (str.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else{
			//�������Ʒֿ�
			string s1 = str.substr(0, str.find('-'));
			string s2 = str.substr(str.find('-') + 1);

			//�Ƶ�����
			//int n1 = count(s1.begin(), s1.end(), ' ') + 1;
			//int n2 = count(s2.begin(), s2.end(), ' ') +1;
			int n1 = countCards(s1);
			int n2 = countCards(s2);

			string card1 = s1.substr(0, s1.find(' '));
			string card2 = s2.substr(0, s2.find(' '));

			string tab = "345678910JQKA2";

			//������ͬʱ;�Ƚ���С�ƴ�С
			if (n1 == n2){
				if (tab.find(card1) > tab.find(card2))
					cout << s1 << endl;
				else
					cout << s2 << endl;
			}
			else{
				//������ͬ��ը��
				if (n1 == 4)
					cout << s1 << endl;
				else if (n2 == 4)
					cout << s2 << endl;
				else
					cout << "ERROR" << endl;

			}
		}
	}

	return 0;
}