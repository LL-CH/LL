#include <iostream>
using namespace std;

int main()
{
	int year;
	int day;
	//ÿ���µ�����
	int month[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> year >> day)
	{
		//����2����29��
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			month[1] = 29;
		else
			month[1] = 28;
		for (int i = 0; i < 12; i++)
		{
			if (day <= month[i])
			{
				//����С������µ����������
				printf("%04d-%02d-%02d\n", year, i + 1, day);
				break;
			}
			//�����ȥ��������
			else
			{
				day = day - month[i];
			}
		}
	}
	return 0;
}