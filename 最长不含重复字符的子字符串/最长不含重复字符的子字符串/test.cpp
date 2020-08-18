class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		vector<int> dp(128, -1);//存储每个字符最后出现的位置
		int i = 0, j = 0, res = 0;
		for (; j < s.size(); j++)
		{
			if (dp[s[j]] < i)//前面的子串不含新加的字符
				res = max(res, j - i + 1);
			else//当前字符在之前的子串中出现过            
				i = dp[s[j]] + 1;//更新i，使得i到j没有重复字符
			dp[s[j]] = j;//更改当前字符出现的位置                               
		}
		return res;
	}
};