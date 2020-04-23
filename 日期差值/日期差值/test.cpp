#include <iostream>
using namespace std;

int main()
{
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int y1, y2, m1, m2, d1, d2, n;
	while (scanf("%4d%2d%2d\n%4d%2d%2d", &y1, &m1, &d1, &y2, &m2, &d2) != EOF)
	{
		if (y1 % 400 == 0 || (y1 % 100 && y1 % 4 == 0)){
			month[2] = 29;
		}
		for (n = 1; y1 != y2 || m1 != m2 || d1 != d2; ++n){
			if (++d1 > month[m1])
			{
				d1 = 1;
				if (++m1 > 12)
				{
					m1 = 1;
					++y1;
					if (y1 % 400 == 0 || (y1 % 100 && y1 % 4 == 0)){
						month[2] = 29;
					}
				}
			}
		}
		printf("%d\n", n);
	}
}

