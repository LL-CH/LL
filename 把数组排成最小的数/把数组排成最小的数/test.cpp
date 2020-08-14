class Solution {
public:
	//定义排序规则
	static bool compare(const string &s1, const string s2){
		return s1 + s2 < s2 + s1;
	}

	string minNumber(vector<int>& nums) {
		vector<string> str;
		string ret;
		//转为字符串存入str
		for (auto num : nums){
			str.push_back(to_string(num));
		}
		//排序
		sort(str.begin(), str.end(), compare);
		for (auto s : str)
			ret += s;

		return ret;
	}
};