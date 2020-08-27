//x，y分别指向数组的两端。
//当nums[x] + nums[y] == target时，有解{ nums[x], nums[y] }。
//当nums[x] + nums[y] > target时，y--。这样能使两者之和减小。
//当nums[x] + nums[y] < target时，x++。这样能使两者之和增大

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int x = 0, y = nums.size() - 1;
		while (x < y){
			int s = nums[x] + nums[y];
			if (s == target){
				return vector<int>{nums[x], nums[y]};
			}
			else if (s > target){
				--y;
			}
			else{
				++x;
			}
		}
		return vector<int>{-1, -1};
	}
};