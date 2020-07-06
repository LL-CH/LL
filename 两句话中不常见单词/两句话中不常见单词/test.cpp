class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		string s = A + ' ' + B;
		vector<string> v;
		//���뵥��
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

		// ������һ�εĵ��ʱ�����vRet��
		for (auto e : m){
			if (e.second == 1)
				v.push_back(e.first);
		}

		return v;
	}
};
