//x��y�ֱ�ָ����������ˡ�
//��nums[x] + nums[y] == targetʱ���н�{ nums[x], nums[y] }��
//��nums[x] + nums[y] > targetʱ��y--��������ʹ����֮�ͼ�С��
//��nums[x] + nums[y] < targetʱ��x++��������ʹ����֮������

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int x = 0, y = nums.size() - 1;
		while (x < y){
			int s = nums[x] + nums[y];
			if (s == target){
				return vector<int>{nums[x], nums[y]};
			}
			else if (s > target){
				--y;
			}
			else{
				++x;
			}
		}
		return vector<int>{-1, -1};
	}
};