//* 1. ���Դ�Сд��ֻ������ĸ
//* 2. ͨ����β�Ƚϵķ�ʽ���ж����Ƿ�Ϊ����



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
			s[i] = tolower(s[i]); //���Դ�Сд      
		}

		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			//�ҵ���ߵ�һ��δ�Ƚϵ���ĸ
			while (left<right && !isDigtalOrWord(s[left]))
				left++;
			//�ҵ��ұߵ�һ��δ�Ƚϵ���ĸ
			while (left<right && !isDigtalOrWord(s[right]))
				right--;
			//����������ĸ������ȣ����ǻ���
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
};