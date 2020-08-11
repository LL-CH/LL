//维护一个最大堆一个最小堆，且保证 最大堆和最小堆的 size 平衡
//两个堆平衡 等价于最大堆size==最小堆size || 最大堆size==最小堆size + 1
//最大堆存储较小的一半数据，堆顶为最大，最小堆存较大的一半值，堆顶为最小
//如果数据流的个数是技术，则中位数 是 最大堆的 top()元素， 否则是最大堆和最小堆的平均值

class MedianFinder {
public:
	/** initialize your data structure here. */
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	//元素个数
	int size;

	MedianFinder() {
		size = 0;
	}

	void addNum(int num) {
		size++;
		maxHeap.push(num);
		//将大堆的最大数放入小堆
		minHeap.push(maxHeap.top());
		maxHeap.pop();
		//调整两边元素个数，使得maxHeap元素个数始终大于minheap元素1个或相等
		//如果小堆元素多了，则将小堆堆顶最小值放入大堆
		if (minHeap.size() > maxHeap.size()){
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian() {
		if (size == 0)
			return 0;
		//奇数个元素
		if (size % 2)
			return maxHeap.top();
		else
			return (minHeap.top() + maxHeap.top())*0.5;
	}
};