class Solution {
public:
	//对数字x，如果target-x在hash中，有解{x, target - x}。
	//否则，x入hash。
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_set<int> hash;
		for (auto x : nums){
			if (hash.count(target - x)){
				return vector<int>{x, target - x};
			}
			hash.insert(x);
		}
		return vector<int>{-1, -1};
	}
};