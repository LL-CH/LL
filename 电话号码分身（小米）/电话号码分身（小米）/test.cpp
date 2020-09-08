#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++){
		string str;
		vector<int> flag(26, 0), nums;
		int cnt = 0;
		cin >> str;
		for (int i = 0; i < str.size(); i++){
			flag[str[i] - 'A'] ++;
		}
		//W是"TWO" 中独有的字符 A为0
		//W-A 代表有几个"TWO"	对应数字4
		if (flag['W' - 'A'] > 0){  //2
			for (int i = 0; i < flag['W' - 'A']; i++){
				nums.push_back(4);
				//删除对应个数的T和O
				flag['T' - 'A'] --;
				flag['O' - 'A'] --;
			}
		}
		// "FOUR"  U
		if (flag['U' - 'A'] > 0){  //4
			for (int i = 0; i < flag['U' - 'A']; i++){
				nums.push_back(6);
				flag['F' - 'A'] --;
				flag['O' - 'A'] --;
				flag['R' - 'A'] --;
			}
		}
		//SIX  X
		if (flag['X' - 'A'] > 0){  //6
			for (int i = 0; i < flag['X' - 'A']; i++){
				nums.push_back(8);
				flag['S' - 'A'] --;
				flag['I' - 'A'] --;
			}
		}

		
		if (flag['G' - 'A'] > 0){  //8
			for (int i = 0; i < flag['G' - 'A']; i++){
				nums.push_back(0);
				flag['E' - 'A'] --;
				flag['I' - 'A'] --;
				flag['H' - 'A'] --;
				flag['T' - 'A'] --;
			}
		}

		if (flag['H' - 'A'] > 0){  //3
			for (int i = 0; i < flag['H' - 'A']; i++){
				nums.push_back(5);
				flag['T' - 'A'] --;
				flag['R' - 'A'] --;
				flag['E' - 'A'] --;
				flag['E' - 'A'] --;
			}
		}

		if (flag['F' - 'A'] > 0){  //5
			for (int i = 0; i < flag['F' - 'A']; i++){
				nums.push_back(7);
				flag['I' - 'A'] --;
				flag['V' - 'A'] --;
				flag['E' - 'A'] --;
			}
		}
		//可以用R与Z替换
		if (flag['Z' - 'A'] > 0){  //0
			for (int i = 0; i < flag['Z' - 'A']; i++){
				nums.push_back(2);
				flag['R' - 'A'] --;
				flag['E' - 'A'] --;
				flag['O' - 'A'] --;
			}
		}

		if (flag['V' - 'A'] > 0){  //7
			for (int i = 0; i < flag['V' - 'A']; i++){
				nums.push_back(9);
				flag['S' - 'A'] --;
				flag['E' - 'A'] --;
				flag['E' - 'A'] --;
				flag['N' - 'A'] --;
			}
		}

		if (flag['O' - 'A'] > 0){  //1
			for (int i = 0; i < flag['O' - 'A']; i++){
				nums.push_back(3);
				flag['N' - 'A'] --;
				flag['E' - 'A'] --;
			}
		}

		if (flag['I' - 'A'] > 0){  //9
			for (int i = 0; i < flag['I' - 'A']; i++){
				nums.push_back(1);
				flag['N' - 'A'] --;
				flag['N' - 'A'] --;
				flag['E' - 'A'] --;
			}
		}
		//排序，输出最小数值
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++){
			cout << nums[i];
		}
		cout << endl;

	}

	return 0;
}