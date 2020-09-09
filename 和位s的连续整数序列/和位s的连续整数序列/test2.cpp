vector<vector<int>> findContinuousSequence(int target) {
	vector<vector<int>> vec;

	int small = 1;// �������ڵ���߽�
	int big = 2;// �������ڵ��ұ߽�
	int sum = small+big;// �������������ֵĺ�
	if (target < 3)
		return vec;
	while (small <= target / 2){
		if(sum<target){
			big++;
			sum += big;
		}
		else if(sum>target){
			sum -= small;
			small++;
		}
		else{
			vector<int> tmp;
			for (int i = small; i <= big; i++)
				tmp.push_back(i);
			vec.push_back(tmp);
			sum -= small;
			small++;
		}
	}
	return vec;
}