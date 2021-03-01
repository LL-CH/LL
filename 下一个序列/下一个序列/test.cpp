class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;
		int reverseStart = 0; //��ʼ�ߵ�˳�����㣬���numsȫ����Ļ���ֱ�Ӵ�0��ʼ
		for (int i = nums.size() - 1; i > 0; i--) {
			if (nums[i] > nums[i - 1]) { //����a[i-1] < a[i]�Ľṹ
				reverseStart = i; //��¼��Ҫ��������
				int minalt = nums[i]; //��ӽ�a[i-1]�����ִ���a[i-1]������
				int minindex = i;
				for (int j = i; j < nums.size(); j++) {
					if (nums[j] > nums[i - 1] && nums[j] <= minalt) {
						// ����һ��Ҫ��С�ڵ��ڣ���Ϊ���ظ�����Ļ�Ҫswap�����Ǹ�nums[]]
						// ����ȷ���µ������Ǵ���ԭ������С���Ǹ�
						minalt = nums[j];
						minindex = j;
					}
				}
				swap(nums[i - 1], nums[minindex]);//����a[i-1]��a[k]
				break;
			}
		}
		for (int i = 0; i < (nums.size() - reverseStart) / 2; i++) {
			// ��Ҫ�ߵ����򲿷ֵĳ��ȳ��Զ��������û�
			swap(nums[reverseStart + i], nums[nums.size() - i - 1]);
		}
	}
};