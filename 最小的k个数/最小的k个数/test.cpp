class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> v;
		if (k == 0)
			return v;
		//���ȼ����� Ĭ���Ǵ��
		priority_queue<int> q;
		//��k���������
		for (int i = 0; i < k; ++i)
			q.push(arr[i]);
		//��k��������������
		for (int i = k; i < (int)arr.size(); i++) {
			//�������С������
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