class Solution {
public:
	//�����������
	static bool compare(const string &s1, const string s2){
		return s1 + s2 < s2 + s1;
	}

	string minNumber(vector<int>& nums) {
		vector<string> str;
		string ret;
		//תΪ�ַ�������str
		for (auto num : nums){
			str.push_back(to_string(num));
		}
		//����
		sort(str.begin(), str.end(), compare);
		for (auto s : str)
			ret += s;

		return ret;
	}
};