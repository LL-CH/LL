//����С��10����n�����1n��
//���ڴ���10��������Ҫ�ֽ�Ϊ���ɸ���λ��֮�������ֵĸ����������١�������ֿ��Էֽ�Ϊ��9��8��...��2������֮����Ȼ���С����������ɡ�

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