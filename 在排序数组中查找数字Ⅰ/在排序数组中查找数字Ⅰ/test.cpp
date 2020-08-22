class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;

		int left = 0, right = nums.size() - 1, mid;
		int start, end;

		while (left < right){
			mid = (left + right) / 2;
			if (nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		if (nums[left] != target)
			return 0;
		//第一个target的下标
		start = left;
		right = nums.size();
		while (left < right){
			mid = (left + right) / 2;
			if (nums[mid] <= target)
				left = mid + 1;
			else
				right = mid;
		}
		//最后一个target下标
		end = left;
		return end - start;
	}
};