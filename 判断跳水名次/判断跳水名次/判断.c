#include<stdio.h>
#include <stdlib.h>

int main()
{
	int a = 0;
	int	b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2) + (a == 3) == 1) &&             //由已知条件进行判断
							((b == 2) + (e == 4) == 1) &&
							((c == 1) + (d == 2) == 1) &&
							((c == 5) + (d == 3) == 1) &&
							((e == 4) + (a == 1) == 1))
						{
							if (a*b*c*d*e == 120 && a + b + c + d + e == 15){    //限制1,2,3,4,5几个数只能出现一次,不能重复
								printf("a=%d b=%d c=%d d=%d e=%d \n", a, b, c, d, e);
								break;
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
