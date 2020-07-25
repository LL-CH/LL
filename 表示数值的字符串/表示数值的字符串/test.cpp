#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
	//判断符号
	bool scanInteger(const string str,int& index){
		if (str[index]=='+' || str[index] == '-'){
			index++;
		}
		return scanUnsignedInteger(str, index);
	}

	//判断数字
	bool scanUnsignedInteger(const string str, int& index){
		int start = index;
		while (index!=str.size() && str[index] >= '0' && str[index] <= '9')
			index++;
		return index > start;
	}

	// 数字的格式可以用A.[B][e|EC]或者.B[e|EC]表示，
	// 其中A和C都是整数（可以有正负号，也可以没有），而B是一个无符号整数
	bool isNumber(string str){
		if (str.empty())
			return false;
		int index = 0;
		//字符串开始有空格直接走
		while (str[index] == ' ')
			index++;
		bool flag = scanInteger(str, index);

		// 下面代码用||的原因：
		// 1. 小数可以没有整数部分，例如.123等于0.123；
		// 2. 小数点后面可以没有数字，例如233.等于233.0；
		// 3. 当然小数点前面和后面可以有数字，例如233.666	
		if (str[index] == '.'){
			index++;
			flag = scanUnsignedInteger(str, index) || flag;
		}

		// 下面代码用&&的原因：
		// 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
		// 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4

		if (str[index] == 'e' || str[index] == 'E'){
				index++;
				flag = scanInteger(str, index) && flag;
		}

		while (str[index] == ' ')
			index++;
		return flag && str.empty();
	}
};