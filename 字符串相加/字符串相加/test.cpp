#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		//½øÎ»
		int next = 0;
		string str;
		while (end1 >= 0 || end2 >= 0){
			int val1 = 0, val2 = 0;
			if (end1 >= 0)
				val1 = num1[end1] - '0';
			if (end2 >= 0)
				val2 = num2[end2] - '0';
			int ret = val1 + val2 + next;
			if (ret>9){
				ret -= 10;
				next = 1;
			}
			else{
				next = 0;
			}
			str += (ret + '0');
			--end1;
			--end2;

		}
		if (next == 1){
			str += '1';
		}
		reverse(str.begin(), str.end());
		return str;
	}
};