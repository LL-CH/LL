class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;
		int reverseStart = 0; //开始颠倒顺序的起点，如果nums全倒叙的话就直接从0开始
		for (int i = nums.size() - 1; i > 0; i--) {
			if (nums[i] > nums[i - 1]) { //发现a[i-1] < a[i]的结构
				reverseStart = i; //记录需要倒叙的起点
				int minalt = nums[i]; //最接近a[i-1]并且又大于a[i-1]的数字
				int minindex = i;
				for (int j = i; j < nums.size(); j++) {
					if (nums[j] > nums[i - 1] && nums[j] <= minalt) {
						// 这里一定要用小于等于，因为有重复情况的话要swap最靠后的那个nums[]]
						// 才能确保新的排列是大于原排列最小的那个
						minalt = nums[j];
						minindex = j;
					}
				}
				swap(nums[i - 1], nums[minindex]);//交换a[i-1]与a[k]
				break;
			}
		}
		for (int i = 0; i < (nums.size() - reverseStart) / 2; i++) {
			// 把要颠倒排序部分的长度除以二，两两置换
			swap(nums[reverseStart + i], nums[nums.size() - i - 1]);
		}
	}
};