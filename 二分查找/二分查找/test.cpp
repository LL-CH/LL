class BinarySearch {
public:
	//返回val在数组中第一次出现的下标
	int getPos(vector<int> A, int n, int val) {
		int left = 0;
		int right = n - 1;
		int mid;
		if (n = 0 || A.empty())
			return -1;
		while (left <= right){
			mid = (left + right) / 2;
			if (A[mid] > val)
				right = mid - 1;
			else if (A[mid] < val)
				left = mid + 1;
			else{
				while (A[mid - 1] == val && mid >= left)
					mid--;
				return mid;
			}
		}
		return -1;
	}
};