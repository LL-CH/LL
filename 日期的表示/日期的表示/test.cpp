#include<iostream>
using namespace std;

// ʵ��һ�����Ƶ�������
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		// ��2���������귵��29
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}

		return monthDays[month];
	}

	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "�Ƿ�����" << endl;
		}
	}

	// Date d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// d1 < d2
	// d1.operator<(&d1, d2)
	inline bool operator<(const Date& d) // bool operator<(Date* this, const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;

		return false;
	}

	inline bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// d1 <= d2; => d1 < d2 || d1 == d2
	// d1.operator<=(&d1, d2);
	bool operator<=(const Date& d) // bool operator<=(Date* this, const Date& d)
	{
		return *this < d || *this == d;   // �����������ʵ��
	}

	// d1 > d2 -> !(d1 <= d2)
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// d1 + 10
	// d1 + 100
	// d1 + 1000
	Date operator+(int day)
	{
		Date ret(*this); // ��d1��������һ��ret
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			// ������ڵ��첻�Ϸ�������Ҫ���½���
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;

			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}

	// d1 += 10
	Date& operator+=(int day)
	{	
		if (day<0){
			return *this -= -day;
		}

		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}

		return *this;
	}

	// d1-=10
	Date& operator-=(int day){
		if (day<0){
			return *this += -day;
		}

		_day -= day;
		while (_day <= 0){
			--_month;
			if (_month == 0){
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	// d1 - 10
	Date operator-(int day){
		Date ret = *this;
		ret -= day;
		while (ret._day <= 0){
			--ret._month;
			if (ret._month == 0){
				--ret._year;
				ret._month = 12;
			}
			ret._day = GetMonthDay(ret._day, ret._month);
		}
		return ret;
	}
	// ++d1
	Date& operator++(){
		*this += 1;
		return *this;//���ؼ�֮���ֵ
	}
	//d1++
	Date operator++(int){//Ϊ�˹��ɺ�������
		Date ret(*this);
		*this += 1;
		return ret;//���ؼ�֮ǰ��ֵ
	}
	// --d1
	Date& operator--(){
		*this -= 1;
		return *this;
	}
	// d1--
	Date operator--(int){
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	// d1 - d2
	int operator-(const Date& d);

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

	//int _hour;
	//int _minute;
	//int _second;
};

int main()
{
	Date d1(2020, 4, 11);
	d1.Print();

	Date d2(2020, 2, 29);
	d2.Print();

	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 >= d2) << endl;

	// �Ƿ�Ҫ����һ������������������������Ƿ�������Ķ���������
	Date d4 = d1 + 10000;
	d4.Print();

	/*d1 += 10;
	d1 - 10;
	d1 -= 10;
	d1 - d2;
	d1++;
	d1--;*/
	system("pause");
	return 0;
}