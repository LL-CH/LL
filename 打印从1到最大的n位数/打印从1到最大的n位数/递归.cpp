class Solution
{
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		string number(n, '0');
		for (int i = 0; i <= 9; i++)
			//从高位到低位进行全排列
		{
			number[0] = i + '0';//首字符赋初值
			permutationNumbers(number, n, 1);//设置下一位
		}
		return res;
	}
	//对数字全排列
	void permutationNumbers(string& number, int length, int index) {
		if (index == length) {//递归边界
			saveNumber(number);//存储结果
			return;
		}
		else
		{
			for (int i = 0; i <= 9; i++)
			{
				number[index] = '0' + i;//设置第index位的字符
				permutationNumbers(number, length, index + 1);
			}
		}
	}
	//存储结果
	//只能存储前导非0的排列
	void saveNumber(string number) {
		bool isBegin0 = true;
		string tempStr = "";
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			if (!isBegin0) {
				tempStr += *it;
			}
			it++;
		}
		//从高位到低位全排列，要注意首字符为0时，tempStr为空，不能执行stoi
		if (tempStr != "") {
			int tempNum = stoi(tempStr);
			res.push_back(tempNum);
		}
	}
};