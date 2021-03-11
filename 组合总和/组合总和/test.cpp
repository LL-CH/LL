class Solution {
public:
	void backtrack(vector<int> &candidates, vector<vector<int>> &ans, int start, vector<int>&temp, int target) {
		if (target < 0)
			return;
		if (target == 0) {
			ans.push_back(temp);
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			if (candidates[i] > target)
				break;
			temp.push_back(candidates[i]);
			backtrack(candidates, ans, i, temp, target - candidates[i]);
			temp.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> temp;
		backtrack(candidates, ans, 0, temp, target);
		return ans;
	}
};