#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct file {
	string str;    //保存字符串
	int rows;      //错误所在行
	int quantity;  //数量
};

vector<file> fp;
//将所有字符串收集到容器fp
void getstr(void) {
	string str;
	int row;
	file tmp;
	while (cin >> str >> row) {
		tmp.str = str;
		tmp.rows = row;
		tmp.quantity = 1;
		fp.push_back(tmp);
		tmp.str.clear();
	}
}
//改变容器fp字符串。
//1、超过16个字符的文件名称，只记录文件的最后有效16个字符
//2、只记录最后一个‘\’前面的字符
void changestr(vector<file>& fp) {
	int size = fp.size();
	for (int i = 0; i < size; i++) {
		int strsize = fp[i].str.size();
		for (int j = strsize - 1; j >= 0; j--){
			if (fp[i].str[j] == '\\' || strsize - 1 - j >= 16) {
				fp[i].str = fp[i].str.substr(j + 1, strsize - 1 - j);
				break;
			}
		}
	}
}
//合并相同字符。
//条件：净文件名相同&&行号相同
//数量加1，去除相同项
void merge(vector<file>& fp) {
	for (int i = 0; i < (int)fp.size(); i++) {
		for (int j = i + 1; j < (int)fp.size();){
			if (fp[i].str == fp[j].str && fp[i].rows == fp[j].rows){
				fp[i].quantity++;
				fp.erase(fp.begin() + j);
			}
			else
				j++;
		}
	}
}
//测试用例
//E:\V1R2\product\fpgadrive.c   1325
//E:\V1R2\product\fpgadrive.c   1326
//E:\V1R2\product\fpgadrive.c   1327
int main() {
	getstr();
	changestr(fp);
	merge(fp);
	int size = fp.size();
	if (size > 8){
		for (int i = size - 8; i <= size - 1; i++) {
			cout << fp[i].str << ' ' << fp[i].rows << ' ' << fp[i].quantity << endl;
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << fp[i].str << ' ' << fp[i].rows << ' ' << fp[i].quantity << endl;
		}
	}
	return 0;
}