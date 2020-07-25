#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
	//�жϷ���
	bool scanInteger(const string str,int& index){
		if (str[index]=='+' || str[index] == '-'){
			index++;
		}
		return scanUnsignedInteger(str, index);
	}

	//�ж�����
	bool scanUnsignedInteger(const string str, int& index){
		int start = index;
		while (index!=str.size() && str[index] >= '0' && str[index] <= '9')
			index++;
		return index > start;
	}

	// ���ֵĸ�ʽ������A.[B][e|EC]����.B[e|EC]��ʾ��
	// ����A��C���������������������ţ�Ҳ����û�У�����B��һ���޷�������
	bool isNumber(string str){
		if (str.empty())
			return false;
		int index = 0;
		//�ַ�����ʼ�пո�ֱ����
		while (str[index] == ' ')
			index++;
		bool flag = scanInteger(str, index);

		// ���������||��ԭ��
		// 1. С������û���������֣�����.123����0.123��
		// 2. С����������û�����֣�����233.����233.0��
		// 3. ��ȻС����ǰ��ͺ�����������֣�����233.666	
		if (str[index] == '.'){
			index++;
			flag = scanUnsignedInteger(str, index) || flag;
		}

		// ���������&&��ԭ��
		// 1. ��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣�����.e1��e1��
		// 2. ��e��E����û������ʱ�������ַ������ܱ�ʾ���֣�����12e��12e+5.4

		if (str[index] == 'e' || str[index] == 'E'){
				index++;
				flag = scanInteger(str, index) && flag;
		}

		while (str[index] == ' ')
			index++;
		return flag && str.empty();
	}
};