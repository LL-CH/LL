#include<iostream>
#include<string>
using namespace std;

//�����ַ�
int firstUniqChar(string s) {
	// ͳ��ÿ���ַ����ֵĴ���
	int count[256] = { 0 };
	int size = s.size();
	for (int i = 0; i < size; ++i)
		count[s[i]] += 1;
	// �����ַ������ǰ������ֻ����һ�ε��ַ�
	for (int i = 0; i < size; ++i)
	if (1 == count[s[i]])
		return i;

	return -1;
}

//�����±�
class Solution {
public:
	int firstUniqChar2(string s) {
		int len = s.size();
		int cont[26] = { 0 };
		for (int i = 0; i<len; i++){
			cont[s[i] - 'a']++;
		}
		for (int j = 0; j<len; j++){
			if (cont[s[j] - 'a'] == 1)
				return j;
		}
		return -1;
	}
};

int main(){
	string str;
	while (getline(cin, str))
	{
		int res = firstUniqChar(str);
		if (res == -1)
			cout << -1 << endl;
		else
			cout << str[res] << endl;
	}
	return 0;
}