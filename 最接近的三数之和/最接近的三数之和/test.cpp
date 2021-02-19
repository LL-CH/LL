class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int res = 10000000;
		int size = nums.size();
		if (size < 3)   
			return 0;          // ����
		std::sort(nums.begin(), nums.end());// ����Ĭ�ϵ�����
		for (int i = 0; i < size; i++)      // �̶���һ������ת��Ϊ������֮��
		{
			int left = i + 1;
			int right = size - 1;
			while (left < right)
			{
				int temp;                    //��ֵ
				if (res > target) temp = res - target;
				else temp = target - res;
				if (nums[left] + nums[right] > target - nums[i]) {
					if (temp > nums[left] + nums[right] - target + nums[i])
						res = nums[left] + nums[right] + nums[i];
					right--;    // ����֮��̫����ָ������
				}
				else if (nums[left] + nums[right] < target - nums[i]) {
					if (temp > target - nums[left] - nums[right] - nums[i])
						res = nums[left] + nums[right] + nums[i];
					left++;     // ����֮��̫С����ָ������
				}
				else
					return target;
			}
		}
		return res;
	}
};