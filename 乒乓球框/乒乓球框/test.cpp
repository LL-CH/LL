#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main(){
	string s1;
	string s2;
	while (cin >> s1 >> s2){
		//也可以用map
		unordered_map<char, int> mapa, mapb;
		//将s1和s2的数据放入map中
		for (int i = 0; i < s1.size(); i++){
			mapa[s1[i]]++;
		}
		for (int i = 0; i<s2.size(); i++){
			mapb[s2[i]]++;
		}
		//定义一个标志位，判断是否符合
		bool flag = true;
		//遍历s2，判断其是否满足条件，不满足则将flag置为flase，输出No，跳出循环
		for (unordered_map<char, int>::iterator it = mapb.begin(); it != mapb.end(); it++){
			if (it->second>mapa[it->first]){
				cout << "No" << endl;
				flag = false;
				break;
			}
		}
		if (flag == true)
			cout << "Yes" << endl;
	}
	return 0;
}