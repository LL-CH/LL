//1、将数据放入一个数组中，进行排序，返回k-个数
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		vector<int> v;
		for (auto& e : matrix){
			for (int i : e)
				v.push_back(i);
		}

		sort(v.begin(), v.end());
		return v[k - 1];
	}
};

//2、二分查找
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int l = matrix[0][0];
		int r = matrix[n - 1][n - 1];

		while (l < r){
			int mid = (l + r) >> 1;
			int num = 0, i = n - 1, j = 0; //从左下角找
			while (i >= 0 && j < n) {  // 统计矩阵中小于等于mid的元素个数
				if (matrix[i][j] <= mid) {
					num += i + 1;
					j++;
				}
				else {
					i--;
				}
			}

			if (num < k)
				l = mid + 1;
			else
				r = mid;
		}
		return r;
	}
};