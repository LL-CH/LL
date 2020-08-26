class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		//ret为只出现一次的两个数的异或结果
		int ret = 0;
		for (int n : nums)
			ret ^= n;
		int pos = 1;
		vector<int> v(2, 0);
		//通过pos找到第一个ret的1出现的位置
		//pos位置置1，其余位为0
		//pos位置，这两个数一个为1，一个为0
		while ((pos & ret) == 0)
			pos <<= 1;
		//通过pos数找到这两个数
		for (int n : nums)
		if (pos & n)
			v[0] ^= n;
		else
			v[1] ^= n;
		return v;
	}
};