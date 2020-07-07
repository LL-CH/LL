#include<iostream>

using namespace std;

//每个月单天收益
int sy(int month){
	int a[13] = { 0, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2 };
	return a[month];
}

//每个月天数
int days(int year, int month){
	int mday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		mday[2] += 1;

	return mday[month];
}

int main(){
	int y1, m1, d1, y2, m2, d2;
	while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2){
		int sum = 0;
		if (y1 == y2 && m1 == m2 && d1 == d2)
			sum += sy(m1);

		if (y1 == y2 && m1 == m2 && d1 != d2)
			sum += (d2 - d1 + 1)*sy(m1);

		if (y1 == y2 && m1 != m2){
			sum += (days(y1, m1) - d1 + 1)*sy(m1);
			for (int i = m1 + 1; i < m2; i++){
				sum += days(y1, i)*sy(i);
			}
			sum += d2*sy(m2);
		}

		if (y1 != y2){
			sum += (days(y1, m1) - d1 + 1)*sy(m1);
			m1++;
			if (m1 == 13){
				y1++;
				m1 = 1;
			}
			while (y1 <= y2){
				sum += days(y1, m1)*sy(m1);
				m1++;
				if (m1 == 13){
					y1++;
					m1 = 1;
				}
			}
		}
		cout << sum << endl;
	}

	return 0;
}