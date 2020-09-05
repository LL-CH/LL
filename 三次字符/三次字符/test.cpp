#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int main(void){
	vector<int> container(127, 0);
	string str;
	getline(cin, str);
	for (int pos = 0; pos < str.length(); pos++){
		//isalpha ÅÐ¶Ï×Ö·ûÊÇ·ñÎªÓ¢ÎÄ
		if (++container[str[pos]] >= 3 && isalpha(str[pos])){
			cout << str[pos] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}