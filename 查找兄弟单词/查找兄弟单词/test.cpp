#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool isbrother(string s1, string s2){
	if (s1.size() == s2.size()){
		if (s1 == s2)
			return false;
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 == s2)
			return true;
	}
	return false;
}

int main(){
	int n;
	while (cin >> n){
		string str;
		string word, res;
		int index;
		vector<string> v;
		for (int i = 0; i < n; i++){
			cin >> str;
			v.push_back(str);
		}

		sort(v.begin(), v.end());
		cin >> word;
		cin >> index;
		int num = 0;
		for (int i = 0; i < n; i++){
			if (isbrother(word, v[i])){
				num++;
				if (index == num)
					res = v[i];
			}
		}
		cout << num << endl;
		if (num >= index)
			cout << res << endl;
	}
	return 0;
}