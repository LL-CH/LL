class Solution {
public:
	//������x�����target-x��hash�У��н�{x, target - x}��
	//����x��hash��
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