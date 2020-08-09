class Solution {
public:
	vector<string> permutation(string s) {
		vector<string> record;
		if (s.empty())
			return record;
		int p = 0;
		unordered_set<string> set_str;
		DFS(s, p, record, set_str);
		return record;
	}

	void DFS(string& s, int p, vector<string>& record, unordered_set<string>& set_str){
		if (p == s.size() - 1 && set_str.find(s) == set_str.end()) {
			record.push_back(s);
			set_str.insert(s);
		}
		for (int i = p; i < s.size(); ++i){
			char temp = s[p];
			s[p] = s[i];
			s[i] = temp;
			DFS(s, p + 1, record, set_str);
			s[i] = s[p];
			s[p] = temp;
		}
	}
};