//给定一个字符串 不大于100
//输出第一次出现的字符

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	string s;

	while (cin >> s){
		vector<bool> a(256, false);
		string res;
		for (auto e : s){
			if (a[e] == false){
				cout << e;
				a[e] = true;
			}
		}
		cout << endl;
	}
	return 0;
}