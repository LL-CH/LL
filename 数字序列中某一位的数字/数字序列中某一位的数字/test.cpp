class Solution {
public:
	int findNthDigit(int n) {
		if (n <= 9)
			return n;
		//��λ��
		n -= 9;
		//��λ���ĸ���
		long long count = 90, dig = 2;
		//����λ��
		while (n > count*dig){
			n -= (count*dig);
			count *= 10;
			dig++;
		}
		//�������ڵ�����
		long long num = pow(10, dig - 1) + n / dig;
		//����պ���������������һλ�Ǿ�����һ�����ֵ����һλ 
		//����n 11 ���������������11����ʵ��Ӧ����10��0
		if (n%dig == 0){
			num--;
			return num % 10;
		}
		//�����������ĵڶ�λ���� 7888 ��ôӦ��78/100%10
		else{
			for (int i = 0; i < (dig - n%dig); i++){
				num /= 10;
			}
			return num % 10;
		}
	}
};