#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//������
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
			flag = 1;//���str[i]Ϊ'+'��str[i]˳����ƣ������־flagΪ1����ʾΪ����   
		}
		else if (cstr[i] == '-')
		{
			i++;
			flag = -1;//���str[i]Ϊ'-'��str[i]˳����ƣ������־flagΪ-1����ʾΪ����   
		}
		long long num = 0;
		while (cstr[i] != '\0')
		{
			if (cstr[i] >= '0' && cstr[i] <= '9')
			{
				//ÿ����һ����0-9����ַ����ͽ������뵽num��       
				num = num * 10 + (cstr[i] - '0');//��һ�����뵽num��ʱҪ������һ��*10�Ľ��������һ�ε�������һλ��ʮ�����£�          
				//�������������򷵻�0
				if (num > INT_MAX)
					return  INT_MAX;
				else if (num < INT_MIN)
					return INT_MIN;
			}
			else{
				return num; // ֻҪ�����������־�ֹͣѭ��
			}
		}
		if (flag < 0)
			num = num * -1;
		return (int)num;
	}
};

//������
class Solution {
public:
	int strToInt(string str) {
		if (str.empty()) return 0;
		if (str[0] >= 'a' && str[0] <= 'z') 
			return 0;
		int i = 0;

		long num = 0;
		// �ո�
		while (str[i] == ' ')
			i++;
		int sign = 1;
		// ����
		if (str[i] == '-'){
			sign = -1;
			i++;
		}
		// ����
		else if (str[i] == '+')
			i++;
		// ��ʽѭ��
		while (i < str.size()){
			if (str[i] >= '0' && str[i] <= '9'){
				num = num * 10 + sign * (str[i] - '0'); //���ģ�string to int
				// ������Χ��ֹͣѭ��
				if (num > INT_MAX)
					return  INT_MAX;
				else if (num < INT_MIN)
					return INT_MIN;
			}
			else{
				return num; // ֻҪ�����������־�ֹͣѭ��
			}
			i++;
		}
		return num;
	}
};
