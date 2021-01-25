class Solution {
public:
	/*int lengthOfLongestSubstring(string s) {  //֮ǰ�Ĵ���,���Ӷ�O(n^2)
	 int  size,i=0,j,k,max=0;
	 size = s.size();
	 for(j = 0;j<size;j++){
		 for(k = i;k<j;k++)
			 if(s[k]==s[j]){
				 i = k+1;
				 break;
			 }
		 if(j-i+1 > max)
			 max = j-i+1;
	 }
	 return max;
 }*/
	int _map[130];
	int lengthOfLongestSubstring(string s) {

		int max = 0;
		int n = s.size();
		for (int i = 0, j = 0; j < n; j++) { //˫ָ�뻬������
			_map[s[j]]++;
			while (_map[s[j]] > 1) { //��ǰ�ж��Ƿ��ظ��Ĵ�Ϊs[i..j],��i�Ƶ��ظ��ַ���λ��
				_map[s[i++]]--; //iָ������
			}
			if (j - i + 1 > max)
				max = j - i + 1;
		}
		return max;
	}
};