class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int max = nums[0];
		int count = 0;
		for (int i = 0; i<nums.size(); i++){
			if (count>0)
				count += nums[i];
			else
				count = nums[i];
			if (count > max)
				max = count;
		}
		return max;
	}
};