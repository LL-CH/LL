#include<iostream>
#include<vector>
#include <string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		int n1 = num1.length() - 1;
		int n2 = num2.length() - 1;
		vector<int> mul(n1 + n2 + 2);//编译器默认初始化为0

		for (int i = n1; i >= 0; i--)
		for (int j = n2; j >= 0; j--) {
			int bitmul = (num1[i] - '0')*(num2[j] - '0');//两个位上的数的乘积
			bitmul += mul[i + j + 1];//先加低位，判断是否有新的进位

			mul[i + j] += bitmul / 10;//高位
			mul[i + j + 1] = bitmul % 10;//低位
		}

		//去掉前导0
		int i = 0;
		while (i < n1 + n2 + 1 && mul[i] == 0)
			i++;
		string multi;
		for (; i < n1 + n2 + 2; i++)
			multi.append(to_string(mul[i]));//string类型的append函数
		return multi;
	}
};