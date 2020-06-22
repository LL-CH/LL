#include<iostream>
#include<string>

using namespace std;

int main(){
	string s1, s2;
	while (cin >> s1 >> s2){
		if (s1.size() > s2.size())
			swap(s1, s2); //找到短的那一个

		string ret; //储存结果
		for (int i = 0; i < s1.size(); i++){
			for (int j = i; j < s1.size(); j++){
				string str = s1.substr(i, j - i + 1);

				if (int(s2.find(str))<0){   //在s2中查找是否有str
					break;
				}
				else{
					if (str.size()>ret.size()) //更新结果
						ret = str;
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}