class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int> > res;
		int n = nums.size();
		if (n < 4)   return res; // 特判
		std::sort(nums.begin(), nums.end()); // 排序
		// 选取第一个数
		for (int i = 0; i < n - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])  // 去重
				continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) // 剪枝
				break;
			if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) // 剪枝
				continue;
			// 选取第二个数
			for (int j = i + 1; j < n - 2; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1]) // 去重
					continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) // 剪枝
					break;
				if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) // 剪枝
					continue;
				// 通过双指针取第三个和第四个数
				int left = j + 1;
				int right = n - 1;
				while (left < right)
				{
					if (nums[left] + nums[right] < target - nums[i] - nums[j])
						left++;     // 此两数之和太小，左指针右移
					else if (nums[left] + nums[right] > target - nums[i] - nums[j])
						right--;    // 此两数之和太大，右指针左移
					else
					{
						// 找到一组解，左右指针内缩，继续寻找
						res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						left++; right--;
						// 去重
						while (left < right && nums[left] == nums[left - 1])   left++;
						while (left < right && nums[right] == nums[right + 1])   right--;
					}
				}
			}
		}
		return res;
	}
};