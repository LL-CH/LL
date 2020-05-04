//* 1. 忽略大小写，只考虑字母
//* 2. 通过首尾比较的方式，判断其是否为回文



class Solution {
public:
	bool isDigtalOrWord(char ch)
	{
		if ((ch >= '0' && ch <= '9')
			|| (ch >= 'A' && ch <= 'Z')
			|| (ch >= 'a' && ch <= 'z'))
			return true;
		return false;
	}

	bool isPalindrome(string s)
	{
		if (s.empty())
			return true;
		for (int i = 0; i<s.size(); ++i)
		{
			s[i] = tolower(s[i]); //忽略大小写      
		}

		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			//找到左边第一个未比较的字母
			while (left<right && !isDigtalOrWord(s[left]))
				left++;
			//找到右边第一个未比较的字母
			while (left<right && !isDigtalOrWord(s[right]))
				right--;
			//左右两边字母若不相等，则不是回文
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
};