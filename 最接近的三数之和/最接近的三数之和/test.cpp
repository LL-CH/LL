class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int res = 10000000;
		int size = nums.size();
		if (size < 3)   
			return 0;          // 特判
		std::sort(nums.begin(), nums.end());// 排序（默认递增）
		for (int i = 0; i < size; i++)      // 固定第一个数，转化为求两数之和
		{
			int left = i + 1;
			int right = size - 1;
			while (left < right)
			{
				int temp;                    //差值
				if (res > target) temp = res - target;
				else temp = target - res;
				if (nums[left] + nums[right] > target - nums[i]) {
					if (temp > nums[left] + nums[right] - target + nums[i])
						res = nums[left] + nums[right] + nums[i];
					right--;    // 两数之和太大，右指针左移
				}
				else if (nums[left] + nums[right] < target - nums[i]) {
					if (temp > target - nums[left] - nums[right] - nums[i])
						res = nums[left] + nums[right] + nums[i];
					left++;     // 两数之和太小，左指针右移
				}
				else
					return target;
			}
		}
		return res;
	}
};