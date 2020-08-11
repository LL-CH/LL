class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		//偶数个数时插入右边最小堆
		if (((min.size() + max.size()) & 1) == 0){
			if (max.size() > 0 && num < max[0]){

				//先入堆，再将最大数取出放入min
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());

				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}

			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
		//奇数个数时插入最大堆
		else{
			if (min.size() > 0 && num > min[0]){
				//先入堆，再把最小值取出，放入max
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