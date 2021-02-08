//法一：直接粗暴
//class solution {
//public:
//	string inttoroman(int num) {
//		string result = "";
//		while (num >= 1000) {
//			result += "m";
//			num -= 1000;
//		}
//		if (num >= 900) {
//			result += "cm";
//			num -= 900;
//		}
//		if (num >= 500) {
//			result += "d";
//			num -= 500;
//		}
//		if (num >= 400) {
//			result += "cd";
//			num -= 400;
//		}
//		while (num >= 100) {
//			result += "c";
//			num -= 100;
//		}
//		if (num >= 90) {
//			result += "xc";
//			num -= 90;
//		}
//		if (num >= 50) {
//			result += "l";
//			num -= 50;
//		}
//		if (num >= 40) {
//			result += "xl";
//			num -= 40;
//		}
//		while (num >= 10) {
//			result += "x";
//			num -= 10;
//		}
//		if (num == 9) {
//			result += "ix";
//			num -= 9;
//		}
//		if (num >= 5) {
//			result += "v";
//			num -= 5;
//		}
//		if (num == 4) {
//			result += "iv";
//			num -= 4;
//		}
//		while (num >= 1) {
//			result += "i";
//			num -= 1;
//		}
//		return result;
//	}
//};

//法二 贪心
class Solution
{
public:
	string intToRoman(int num)
	{
		string result;
		vector<int> store = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> strs = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int storeSize = int(store.size());
		//贪心法
		for (int i = 0; i < storeSize; i++)
		{
			while (num >= store[i])
			{
				result.append(strs[i]);
				num -= store[i];
			}
		}
		return result;
	}
};
