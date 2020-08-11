//ά��һ������һ����С�ѣ��ұ�֤ ���Ѻ���С�ѵ� size ƽ��
//������ƽ�� �ȼ�������size==��С��size || ����size==��С��size + 1
//���Ѵ洢��С��һ�����ݣ��Ѷ�Ϊ�����С�Ѵ�ϴ��һ��ֵ���Ѷ�Ϊ��С
//����������ĸ����Ǽ���������λ�� �� ���ѵ� top()Ԫ�أ� ���������Ѻ���С�ѵ�ƽ��ֵ

class MedianFinder {
public:
	/** initialize your data structure here. */
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	//Ԫ�ظ���
	int size;

	MedianFinder() {
		size = 0;
	}

	void addNum(int num) {
		size++;
		maxHeap.push(num);
		//����ѵ����������С��
		minHeap.push(maxHeap.top());
		maxHeap.pop();
		//��������Ԫ�ظ�����ʹ��maxHeapԪ�ظ���ʼ�մ���minheapԪ��1�������
		//���С��Ԫ�ض��ˣ���С�ѶѶ���Сֵ������
		if (minHeap.size() > maxHeap.size()){
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian() {
		if (size == 0)
			return 0;
		//������Ԫ��
		if (size % 2)
			return maxHeap.top();
		else
			return (minHeap.top() + maxHeap.top())*0.5;
	}
};