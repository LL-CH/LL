class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		//ż������ʱ�����ұ���С��
		if (((min.size() + max.size()) & 1) == 0){
			if (max.size() > 0 && num < max[0]){

				//����ѣ��ٽ������ȡ������min
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());

				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}

			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
		//��������ʱ��������
		else{
			if (min.size() > 0 && num > min[0]){
				//����ѣ��ٰ���Сֵȡ��������max
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());

				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());

		}
	}

	double findMedian() {
		int size = min.size() + max.size();
		if (size == 0)
			return 0;
		if (size % 2)
			return min[0];
		else
			return (min[0] + max[0])*0.5;
	}

private:
	vector<int> min;
	vector<int> max;
};