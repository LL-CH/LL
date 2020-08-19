class Solution {
public:
	int nthUglyNumber(int n) {
		if (n < 1)
			return 0;
		vector<int> ugly(n, 0);
		//��������Ϊ1
		ugly[0] = 1;
		//��ʼ�ֱ�ָ���������������һ��Ԫ��,������������������������ģ��ֱ����ugly����Ԫ�طֱ����2,3,5�õ���
		int i = 0, j = 0, k = 0;
		for (int m = 1; m < n; m++){
			//ȡ��С��
			int tmp = min(ugly[i] * 2, min(ugly[j] * 3, ugly[k] * 5));
			//���������������ͬԪ�أ�����ֻҪ����С�ģ���Ҫ�ƶ�ָ��
			if (tmp == ugly[i] * 2)
				i++;
			if (tmp == ugly[j] * 3)
				j++;
			if (tmp == ugly[k] * 5)
				k++;
			ugly[m] = tmp;
		}
		return ugly[n - 1];
	}
};