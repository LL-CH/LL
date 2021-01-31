class Solution {
public:
	int myAtoi(string str) {
		long res = 0;
		int flag = 0; // flag == 0 Ϊ��ʼ״̬ ��1 Ϊ������״̬ ��2Ϊ������
		for (char i : str)
		{
			if (flag == 0 && i == ' ')
				continue;
			else if (flag == 0 && i == '+')
				flag = 1;
			else if (flag == 0 && i == '-')
				flag = 2;
			else if (i >= '0' && i <= '9')
			{
				if (flag == 0)flag = 1;
				int tmp = i - '0';
				res = res * 10 + tmp;
				if (res > INT_MAX)break;
			}
			else break;
		}
		if (flag == 1 && res > INT_MAX)res = INT_MAX;
		else if (flag == 2)
		{
			res = -res;
			if (res < INT_MIN)res = INT_MIN;
		}
		return res;
	}
};