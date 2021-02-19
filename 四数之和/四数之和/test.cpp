class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int> > res;
		int n = nums.size();
		if (n < 4)   return res; // ����
		std::sort(nums.begin(), nums.end()); // ����
		// ѡȡ��һ����
		for (int i = 0; i < n - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])  // ȥ��
				continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) // ��֦
				break;
			if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) // ��֦
				continue;
			// ѡȡ�ڶ�����
			for (int j = i + 1; j < n - 2; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1]) // ȥ��
					continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) // ��֦
					break;
				if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) // ��֦
					continue;
				// ͨ��˫ָ��ȡ�������͵��ĸ���
				int left = j + 1;
				int right = n - 1;
				while (left < right)
				{
					if (nums[left] + nums[right] < target - nums[i] - nums[j])
						left++;     // ������֮��̫С����ָ������
					else if (nums[left] + nums[right] > target - nums[i] - nums[j])
						right--;    // ������֮��̫����ָ������
					else
					{
						// �ҵ�һ��⣬����ָ������������Ѱ��
						res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						left++; right--;
						// ȥ��
						while (left < right && nums[left] == nums[left - 1])   left++;
						while (left < right && nums[right] == nums[right + 1])   right--;
					}
				}
			}
		}
		return res;
	}
};