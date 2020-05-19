#include<iostream>
#include <vector>
using namespace std;

//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int val = 0;
		for (auto a : nums){
			val ^= a;
		}
		return val;
	}
};

//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//统计每个数每一位中1的个数
		int bit[32] = { 0 };
		for (auto val : nums)
		{
			for (size_t i = 0; i < 32; i++)
			{
				if (val & (1 << i))
					bit[i]++;

			}
		}

		int num = 0;
		for (size_t i = 0; i < 32; i++)
		{
			//3n+1个1的位就是单个数的位
			if (bit[i] % 3 == 1)
			{
				num |= (1 << i);
			}
		}
		return num;
	}
};

//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int val = 0;
		//val为两个单独的数的异或结果
		for (auto e : nums)
		{
			val ^= e;
		}

		size_t i = 0;
		for (i; i < 32; i++)
		{
			if (val & (1 << i))
				break;
		}

		int num1 = 0, num2 = 0;
		for (auto a : nums)
		{
			if (a & (1 << i))
				num1 ^= a;
			else
				num2 ^= a;
		}
		vector<int> v;
		v.push_back(num1);
		v.push_back(num2);

		return v;
	}
};