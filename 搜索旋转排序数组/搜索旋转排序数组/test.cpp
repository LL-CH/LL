class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return -1;
		}
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			//选择数组的最右端进行标准；
			if (nums[mid] > nums[right]) {
				//左端一定是升序序列；
				//首先判断是否在左端口;
				if (nums[left] <= target && target <= nums[mid]) {
					right = mid;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				//右端是升序序列；
				if (nums[mid] < target && target <= nums[right]) {
					//下一轮搜索的区间[mid+1,right]
					left = mid + 1;
				}
				else {
					//下一轮搜索的的区间[left,mid]
					right = mid;
				}
			}
		}
		if (nums[left] == target) {
			return left;
		}
		return -1;
	}
};