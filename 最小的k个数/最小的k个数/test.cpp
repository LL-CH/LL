class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> v;
		if (k == 0)
			return v;
		//优先级队列 默认是大堆
		priority_queue<int> q;
		//将k个数据入堆
		for (int i = 0; i < k; ++i)
			q.push(arr[i]);
		//将k后面的数依次入堆
		for (int i = k; i < (int)arr.size(); i++) {
			//比最大数小，插入
			if (q.top() > arr[i]) {
				q.pop();
				q.push(arr[i]);
			}
		}
		for (int i = 0; i < k; ++i) {
			v.push_back(q.top());
			q.pop();
		}
		return v;
	}
};