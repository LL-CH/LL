#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.empty()) return 0;

		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
		int result = nums[0];
		int times = 1; // 次数

		for (int i = 1; i < nums.size(); ++i)
		{
			if (times == 0)
			{
				// 更新result的值为当前元素，并置次数为1
				result = nums[i];
				times = 1;
			}
			else if (nums[i] == result)
			{
				++times; // 相同则加1
			}
			else
			{
				--times; // 不同则减1               
			}
		}

		// 判断result是否符合条件，即出现次数大于数组长度的一半
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
		// 因为用到了sort，时间复杂度O(NlogN)，并非最优
		if (numbers.empty()) return 0;

		sort(numbers.begin(), numbers.end()); // 排序，取数组中间那个数
		int mid = numbers[numbers.size() / 2];

		int count = 0; // 出现次数
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == mid) ++count;
		}

		return (count>numbers.size() / 2) ? mid : 0;
	}
};