class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		//创建一个能容纳最大值的字符数组,由于有一位要存储'\0'，因此要开大一格
		char* number = new char[n + 1];
		//初始全部设置为0
		memset(number, '0', n);
		number[n] = '\0';//第n位设为'\0'
		while (!Increment(number))
		{
			Print(number);
		}
		delete[]number;//注意要释放内存
		return res;
	}

	bool Increment(char* number) {//形参传递char*指针
		bool isOverflow = false;//检测是否越界
		int nTakeOver = 0;//存储进位
		int nLength = strlen(number);//长度为n,不是n+1
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				//如果是第一位，进位
			{
				nSum++;
			}
			if (nSum >= 10)
				//有进位
			{
				if (i == 0)
					//如果是最高位有进位，说明超过了给定得到最大值，越界
				{
					isOverflow = true;
				}
				else//非最高位有进位
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//对第i位进行设置
				}
			}
			else//没有进位
				//设置第i位数字
				//并直接跳出循环
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}

	void Print(char* number)
		//形参传递char*指针，此处改变形参number指向的位置，不会使原始的number指针所指位置改变
	{
		string s = "";
		bool isBegin0 = true;
		while (*number != '\0')
		{
			if (isBegin0 && *number != '0') isBegin0 = false;
			//碰到'0'，则不输出
			if (!isBegin0)
			{
				s += *number;
			}
			number++;
		}
		int num = stoi(s);//转为整数
		res.push_back(num);
	}
};