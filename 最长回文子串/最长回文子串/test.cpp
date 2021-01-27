//cbbd���bbd��
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		��̬�滮
//		int len = s.size();
//		if (len < 2)
//			return s;
//		int maxlen = 1;
//		int begin = 0;//�Ӵ���ʼλ��
//
//		dp[i][j]��ʾs[i...j]�Ƿ�Ϊ���Ĵ�
//		vector<vector<int>> dp(len , vector<int>(len));
//		for (int i = 0; i < len; i++) {
//			dp[i][i] = 1;
//		}
//		���½�����
//		for (int j = 1; j < len; j++) {
//			for (int i = 0; i < j; i++) {
//				if (s[i] != s[j])
//					dp[i][j] = 0;
//				else {
//					if (j - i < 3) {
//						dp[i][j] = 1;
//					}
//					else {
//						dp[i][j] = dp[i + 1][j - 1];
//					}
//				}
//				dp[i][j]=1����s[i...j]ʱ����
//				if (dp[i][j] && j - i + 1 > maxlen) {
//					maxlen = j - i + 1;
//					begin = i;
//				}
//			}
//		}
//		return s.subst(begin, begin + maxlen-1);
//	}
//};
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		string ans;
		for (int l = 0; l < n; ++l) {
			for (int i = 0; i + l < n; ++i) {
				int j = i + l;
				if (l == 0) {
					dp[i][j] = 1;
				}
				else if (l == 1) {
					dp[i][j] = (s[i] == s[j]);
				}
				else {
					dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
				}
				if (dp[i][j] && l + 1 > ans.size()) {
					ans = s.substr(i, l + 1);
				}
			}
		}
		return ans;
	}
};