#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i<n; i++)
		{
			int y, m, d, num;
			int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			cin >> y >> m >> d >> num;
			while (num>days[m - 1])
			{
				if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
					days[1] = 29;
				else
					days[1] = 28;
				num -= days[m - 1] - d;
				d = 0;
				m++;
				if (m == 13)
				{
					y++;
					m = 1;
				}
			}
			printf("%4d-%02d-%02d\n", y, m, num);
		}
	}
	return 0;

}