class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		//retΪֻ����һ�ε��������������
		int ret = 0;
		for (int n : nums)
			ret ^= n;
		int pos = 1;
		vector<int> v(2, 0);
		//ͨ��pos�ҵ���һ��ret��1���ֵ�λ��
		//posλ����1������λΪ0
		//posλ�ã���������һ��Ϊ1��һ��Ϊ0
		while ((pos & ret) == 0)
			pos <<= 1;
		//ͨ��pos���ҵ���������
		for (int n : nums)
		if (pos & n)
			v[0] ^= n;
		else
			v[1] ^= n;
		return v;
	}
};