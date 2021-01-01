#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;
int n;
int a = 0;
int b = 0;
vector<char> q;

int _put(char c){
	if(b>=n-1){
		return 0;
	}
	b++;
	q.push_back(c);
	return 1;
}

int _out(vector<char> &q){
	if(a==b){
		return 0;
	}
	a++;
	b--;
	q.erase(q.begin());
	return 1;
}

int main(){
	string s;
	while(cin>>n){
		int count1 = 0;
		int count2 = 0;
		while(getline(cin,s)){
			if (s == "END")
				break;
			if(s[0]=='P'){
				int ret = _put(s[s.size() - 1]);
				if (ret == 0)
					count1++;
			}
			if(s[0]=='D'){
				int ret = _out(q);
				if (ret == 0)
					count2++;
			}
		}
		cout << count1 << endl;
		cout << count2 << endl;
		for (int i = 0; i < q.size();i++){
			cout << q[i];
		}
		//system("pause");
	}
	system("pause");
	return 0;
}