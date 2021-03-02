class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return -1;
		}
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			//ѡ����������Ҷ˽��б�׼��
			if (nums[mid] > nums[right]) {
				//���һ�����������У�
				//�����ж��Ƿ�����˿�;
				if (nums[left] <= target && target <= nums[mid]) {
					right = mid;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				//�Ҷ����������У�
				if (nums[mid] < target && target <= nums[right]) {
					//��һ������������[mid+1,right]
					left = mid + 1;
				}
				else {
					//��һ�������ĵ�����[left,mid]
					right = mid;
				}
			}
		}
		if (nums[left] == target) {
			return left;
		}
		return -1;
	}
};