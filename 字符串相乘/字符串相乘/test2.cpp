/*思路：

* 1. 下翻转数据
* 2. 按位相乘
* 3. 将乘得的结果进行错位相加，模拟乘法的笔算过程
*/

class Solution
{
public:
	void MulItem(string &tmp, string &num1, char a)
	{
		int i = 0, sign = 0;
		int mul = 0;
		while (i < num1.size())
		{
			mul = (num1[i] - '0') * (a - '0') + sign;
			if (mul >= 10)
			{
				sign = mul / 10;
				mul %= 10;
			}
			else
				sign = 0;
			tmp.push_back(mul + '0');
			i++;
		}
		if (sign > 0)
			tmp.push_back(sign + '0');
	}
	//对应为相加，sign进位采用引用传递
	int AddItem(int a, int b, int &sign)
	{
		int add = a + b + sign;
		if (add >= 10)
		{
			sign = 1;
			add -= 10;

		}
		else
			sign = 0;
		return add;
	}
	//错位相加
	void MoveAdd(string &result, string &tmp, int k)
	{
		int i, j;
		i = k;
		j = 0;
		int sign = 0;
		while (i<result.size() && j<tmp.size())
		{
			result[i] = AddItem(result[i] - '0', tmp[j] - '0', sign) + '0';
			i++;
			j++;
		}
		while (i<result.size() && sign)
		{
			result[i] = AddItem(result[i] - '0', 0, sign) + '0';
			i++;
		}
		while (j < tmp.size())
		{
			int v = AddItem(0, tmp[j] - '0', sign);
			result.push_back(v + '0');
			j++;
		}
		if (sign)
			result.push_back(sign + '0');
	}

	string multiply(string num1, string num2)
	{
		//先翻转数据，方便进位处理
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string tmp, result;
		for (int i = 0; i < num2.size(); ++i)
		{
			//使用num2的每一个数据乘以num1
			MulItem(tmp, num1, num2[i]);
			//将乘得的结果进行错位相加
			MoveAdd(result, tmp, i);
			tmp.clear();
		}
		while (result.size() != 1 && result.back() == '0')
			result.pop_back();

		//翻转数据，恢复数据
		reverse(result.begin(), result.end());
		return result;
	}
};