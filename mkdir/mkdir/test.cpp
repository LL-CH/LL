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
			if ((pos == string::npos) || (pos != 0) || (*it)[(*next).size()] != '/')//判断是不是后边这个串的子串，并且开始位置相同，满足条件不用输出
				cout << "mkdir -p " << *next << endl;
			it = next;
		}
		cout << "mkdir -p " << *(--st.end()) << endl;//无论何种情况最后一个一定会出输出
		cout << endl;
	}
	return 0;
}