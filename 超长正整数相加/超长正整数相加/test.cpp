#include<iostream>
#include<string>

using namespace std;

int main()
{
	//两个正整数字符串相加
	string a, b;
	while (cin >> a >> b){
		int sum = 0;
		int flag = 0;
		while (a.size()<b.size()){
			a = "0" + a;
		}
		while (a.size()>b.size()){
			b = "0" + b;
		}

		for (int i = a.size() - 1; i > -1; i--){
			sum = a[i] - '0' + b[i] - '0' + flag;
			a[i] = sum % 10 + '0';
			if (sum / 10)
				flag = 1;
			else
				flag = 0;
		}
		if (flag)
			a = a + "1";
		cout << a << endl;
	}
	return 0;
}