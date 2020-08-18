class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		vector<int> dp(128, -1);//�洢ÿ���ַ������ֵ�λ��
		int i = 0, j = 0, res = 0;
		for (; j < s.size(); j++)
		{
			if (dp[s[j]] < i)//ǰ����Ӵ������¼ӵ��ַ�
				res = max(res, j - i + 1);
			else//��ǰ�ַ���֮ǰ���Ӵ��г��ֹ�            
				i = dp[s[j]] + 1;//����i��ʹ��i��jû���ظ��ַ�
			dp[s[j]] = j;//���ĵ�ǰ�ַ����ֵ�λ��                               
		}
		return res;
	}
};