#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//有问题
class Solution {
public:
	int StrToInt(string str)
	{
		int len = str.size();
		int flag = 1;
		if (len == 0)
			return 0;
		const char *cstr = str.c_str();
		if (cstr == NULL)
			return 0;
		int i = 0;
		while (cstr[i] == ' ')
		{
			i++;
		}
		if (cstr[i] == '+')
		{
			i++;
			flag = 1;//如果str[i]为'+'，str[i]顺序后移，并令标志flag为1，表示为正数   
		}
		else if (cstr[i] == '-')
		{
			i++;
			flag = -1;//如果str[i]为'-'，str[i]顺序后移，并令标志flag为-1，表示为负数   
		}
		long long num = 0;
		while (cstr[i] != '\0')
		{
			if (cstr[i] >= '0' && cstr[i] <= '9')
			{
				//每遍历一个在0-9间的字符，就将其输入到num中       
				num = num * 10 + (cstr[i] - '0');//下一次输入到num中时要加上上一次*10的结果，即上一次的数左移一位（十进制下）          
				//如果数据溢出，则返回0
				if (num > INT_MAX)
					return  INT_MAX;
				else if (num < INT_MIN)
					return INT_MIN;
			}
			else{
				return num; // 只要遇到不是数字就停止循环
			}
		}
		if (flag < 0)
			num = num * -1;
		return (int)num;
	}
};

//无问题
class Solution {
public:
	int strToInt(string str) {
		if (str.empty()) return 0;
		if (str[0] >= 'a' && str[0] <= 'z') 
			return 0;
		int i = 0;

		long num = 0;
		// 空格
		while (str[i] == ' ')
			i++;
		int sign = 1;
		// 负号
		if (str[i] == '-'){
			sign = -1;
			i++;
		}
		// 正号
		else if (str[i] == '+')
			i++;
		// 正式循环
		while (i < str.size()){
			if (str[i] >= '0' && str[i] <= '9'){
				num = num * 10 + sign * (str[i] - '0'); //核心：string to int
				// 超过范围就停止循环
				if (num > INT_MAX)
					return  INT_MAX;
				else if (num < INT_MIN)
					return INT_MIN;
			}
			else{
				return num; // 只要遇到不是数字就停止循环
			}
			i++;
		}
		return num;
	}
};
