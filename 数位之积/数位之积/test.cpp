//对于小于10的数n，输出1n。
//对于大于10的数，需要分解为若干个个位数之积，数字的个数尽可能少。这个数字可以分解为以9，8，...，2的因子之积。然后从小到大输出即可。

class BinarySearch {
public:
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