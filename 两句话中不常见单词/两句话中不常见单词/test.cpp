class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		string s = A + ' ' + B;
		vector<string> v;
		//分离单词
		for (int i = 0; i < s.size(); i++){
			string ret;
			while (s[i] != ' ' && i < s.size()){
				ret += s[i];
				++i;
			}
			v.push_back(ret);
		}

		unorder_map<string, int> m;
		for (auto e : v)
			m[e]++;

		v.clear();

		// 将出现一次的单词保存在vRet中
		for (auto e : m){
			if (e.second == 1)
				v.push_back(e.first);
		}

		return v;
	}
};
