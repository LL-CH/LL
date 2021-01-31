class Solution {
public:
	int reverse(int x) {
		long long ans = 0;//·ÀÖ¹Òç³ö
		while (x) {
			ans = x % 10 + ans * 10;
			x /= 10;
		}
		return ans > INT_MAX || ans < INT_MIN ? 0 : ans;
	}
};