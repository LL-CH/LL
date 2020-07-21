#include<iostream>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (x == 1 || n == 0) 
			return 1;
		double ans = 1;
		long num = n;
		//当为负的次方时取倒数
		if (n < 0){
			num = -num;
			x = 1 / x;
		}
		while (num){
			//奇数次方先乘一个x，偶数直接取最后的数值
			if (num & 1) ans *= x;
			x *= x;
			num >>= 1;
		}
		return ans;
	}
};

int main(){
	Solution s;
	double res = s.myPow(2, 10);
	cout << res << endl;
	system("pause");
}