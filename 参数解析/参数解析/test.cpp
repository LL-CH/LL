#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	string str;
	while (getline(cin, str)){
		vector<string> v;
		string s = "";
		bool ch = false;
		int count = 0;
		for (int i = 0; i < str.size(); i++){
			if (str[i] == '"' && ch == false){
				ch = true;
				continue;
			}
			if (str[i] == '"' && ch == true){
				ch = false;
				continue;
			}
			if (str[i] == ' ' && ch == false){
				v.push_back(s);
				s = "";
				continue;
			}
			s += str[i];
		}
		v.push_back(s);
		cout << v.size() << endl;
		for (auto e : v){
			cout << e << endl;
		}
	}

	return 0;
}