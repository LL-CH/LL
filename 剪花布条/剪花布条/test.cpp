#include<iostream>
#include<string>

using namespace std;

int main(){
	string s1, s2;
	while (cin >> s1 >> s2){
		size_t i = 0;
		int sum = 0;
		while (i != s1.size()){
			//ȡС������С�����в���
			if (s1.substr(i, s2.size()) == s2){
				i += s2.size();
				sum++;
			}
			else
				i++;
		}

		cout << sum << endl;
	}
	return 0;
}