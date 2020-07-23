class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		//����һ�����������ֵ���ַ�����,������һλҪ�洢'\0'�����Ҫ����һ��
		char* number = new char[n + 1];
		//��ʼȫ������Ϊ0
		memset(number, '0', n);
		number[n] = '\0';//��nλ��Ϊ'\0'
		while (!Increment(number))
		{
			Print(number);
		}
		delete[]number;//ע��Ҫ�ͷ��ڴ�
		return res;
	}

	bool Increment(char* number) {//�βδ���char*ָ��
		bool isOverflow = false;//����Ƿ�Խ��
		int nTakeOver = 0;//�洢��λ
		int nLength = strlen(number);//����Ϊn,����n+1
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				//����ǵ�һλ����λ
			{
				nSum++;
			}
			if (nSum >= 10)
				//�н�λ
			{
				if (i == 0)
					//��������λ�н�λ��˵�������˸����õ����ֵ��Խ��
				{
					isOverflow = true;
				}
				else//�����λ�н�λ
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//�Ե�iλ��������
				}
			}
			else//û�н�λ
				//���õ�iλ����
				//��ֱ������ѭ��
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}

	void Print(char* number)
		//�βδ���char*ָ�룬�˴��ı��β�numberָ���λ�ã�����ʹԭʼ��numberָ����ָλ�øı�
	{
		string s = "";
		bool isBegin0 = true;
		while (*number != '\0')
		{
			if (isBegin0 && *number != '0') isBegin0 = false;
			//����'0'�������
			if (!isBegin0)
			{
				s += *number;
			}
			number++;
		}
		int num = stoi(s);//תΪ����
		res.push_back(num);
	}
};