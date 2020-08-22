class Solution {
public:
	int missingNumber(vector<int>& nums) {
		if (nums.empty())
			return -1;
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (nums[mid] > mid)
				right = mid - 1;
			else
				left = mid + 1;
		}
		//if(nums[left]==left)
		// return nums.size();
		return left;
	}
};