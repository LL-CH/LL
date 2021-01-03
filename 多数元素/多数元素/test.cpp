#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main(){
	string str;
	while (getline(cin, str)){
		vector<int> v;
		for (size_t i = 0; i < str.size(); i++){
			if (str[i] != ' ')
				v.push_back(str[i] - '0');
		}
		sort(v.begin(), v.end());
		int mid = v.size() / 2;
		int count = 0;
		for (int i = 0; i<v.size(); i++){
			if (v[i] == v[mid])
				count++;
		}
		if (count>mid)
			cout << v[mid] << endl;
	}

	return 0;
}

