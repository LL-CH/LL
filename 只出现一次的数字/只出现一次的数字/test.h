#include<iostream>
#include <vector>
using namespace std;

//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ���������
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

//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ�����������
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//ͳ��ÿ����ÿһλ��1�ĸ���
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
			//3n+1��1��λ���ǵ�������λ
			if (bit[i] % 3 == 1)
			{
				num |= (1 << i);
			}
		}
		return num;
	}
};

//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ���������
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int val = 0;
		//valΪ�������������������
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