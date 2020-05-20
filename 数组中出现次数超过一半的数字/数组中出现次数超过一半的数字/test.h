#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.empty()) return 0;

		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
		int result = nums[0];
		int times = 1; // ����

		for (int i = 1; i < nums.size(); ++i)
		{
			if (times == 0)
			{
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
				result = nums[i];
				times = 1;
			}
			else if (nums[i] == result)
			{
				++times; // ��ͬ���1
			}
			else
			{
				--times; // ��ͬ���1               
			}
		}

		// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
		times = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] == result) ++times;
		}

		return (times > nums.size() / 2) ? result : 0;
	}
};

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		// ��Ϊ�õ���sort��ʱ�临�Ӷ�O(NlogN)����������
		if (numbers.empty()) return 0;

		sort(numbers.begin(), numbers.end()); // ����ȡ�����м��Ǹ���
		int mid = numbers[numbers.size() / 2];

		int count = 0; // ���ִ���
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == mid) ++count;
		}

		return (count>numbers.size() / 2) ? mid : 0;
	}
};