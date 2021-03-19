#include<iostream>
#include<string>
#include<unordered_map>
#include <unordered_set>

using namespace std;

int main(){
	//n个号码,m个字段
	int n, m;
	//记录连续数字出现的次数
	unordered_map<string, int> _map;
	cin >> n >> m;
	//存储号码，用set避免重复
	unordered_set<string> phone;
	string str;
	//将号码存入phone中
	while(n--){
		cin >> str;
		if(str.size()!=11)
			continue;
		phone.insert(str);
	}

	unordered_set<string>::iterator it = phone.begin();
	for (it; it != phone.end();it++){
		str = *it;
		unordered_set<string> _char;
		////将一个手机号码所有的连续组合方式进行存储，用空间替换时间
		for (int i = 0; i < 11;i++){
			string tmp;
			for (int j = i; j < 11;j++){
				tmp += str[j];
				_char.insert(tmp);
			}
		}
		//计数
		for(auto e : _char){
			_map[e]++;
		}
	}
	while(m--){
		cin >> str;
		cout << _map[str] << endl;
	}

	return 0;
}