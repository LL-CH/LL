#include <iostream>
using namespace std;

int main()
{
	int year;
	int day;
	//每个月的天数
	int month[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> year >> day)
	{
		//闰年2月有29天
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			month[1] = 29;
		else
			month[1] = 28;
		for (int i = 0; i < 12; i++)
		{
			if (day <= month[i])
			{
				//输入小于这个月的天数就输出
				printf("%04d-%02d-%02d\n", year, i + 1, day);
				break;
			}
			//否则减去本月天数
			else
			{
				day = day - month[i];
			}
		}
	}
	return 0;
}