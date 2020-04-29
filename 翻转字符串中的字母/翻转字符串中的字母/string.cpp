
class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.empty())
			return;
		int a = 0;
		int b = s.size() - 1;
		while (a<b){
			swap(s[a], s[b]);
			a++;
			b--;
		}
	}
};