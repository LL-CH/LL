//一个有序数组进行左移，找到此时x的下标

class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		int start = 0;
		int end = n - 1;
		int mid = 0;
		while (start <= end){
			mid = (start + end) / 2;
			if (n < 2){
				return n;
			}
			if (A[mid] == x)
				return mid;
			if (A[mid]<x){
				if (A[mid]<A[end] && x>A[end]){
					end = mid - 1;
				}
				else{
					start = mid + 1;
				}
			}
			else{
				if (A[mid]>A[start] && x < A[start])
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
		return -1;
	}

};