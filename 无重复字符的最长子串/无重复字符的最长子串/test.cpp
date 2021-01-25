class Solution {
public:
	/*int lengthOfLongestSubstring(string s) {  //之前的代码,复杂度O(n^2)
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
		for (int i = 0, j = 0; j < n; j++) { //双指针滑动窗口
			_map[s[j]]++;
			while (_map[s[j]] > 1) { //当前判断是否重复的串为s[i..j],将i移到重复字符的位置
				_map[s[i++]]--; //i指针右移
			}
			if (j - i + 1 > max)
				max = j - i + 1;
		}
		return max;
	}
};