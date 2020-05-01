#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//class Solution {
//public:
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
				if ((flag>0 && num>0x7fffffff) || (flag<0 && num>0x80000000))
					return 0;
				i++;
			}
			else
			{
				return 0;
			}
		}
		if (flag < 0)
			num = num * -1;
		return (int)num;
	}
//};

int main(){
	string s("-l315");
	int res = StrToInt(s);
	printf("%d\n", res);
	system("pause");
	return 0;
}