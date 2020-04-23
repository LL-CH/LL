#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*
*思路：
* 1. 分别求出每一个日期与0000年0月1日距离的天数
* 2. 两个距离天数相减即可得到两个日期相差的天数
*/

//平年从1月到n月的天数
int mon[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
//给出年月日，计算距离0000年0月1日的天数和

int CountDay(int y, int m, int d)
{
	// 计算0-y年的天数
	int yearDay = y * 365 + y / 4 - y / 100 + y / 400;
	// 计算到0-m月的天数
	int monthDay = mon[m - 1];

	if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
		monthDay += 1;
	return yearDay + monthDay + d;

}

int main()
{
	int year1, month1, day1;
	scanf("%4d%2d%2d", &year1, &month1, &day1);
	int n1 = CountDay(year1, month1, day1);
	int year2, month2, day2;
	scanf("%4d%2d%2d", &year2, &month2, &day2);
	int n2 = CountDay(year2, month2, day2);
	cout << abs(n1 - n2) + 1 << endl;
	return 0;
}