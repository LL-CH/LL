#include<iostream>
#include<string>
#include<vector>

//回溯法模板
//if (满足条件的正确结果) {
//	加入结果集；
//		return;
//}
//for (跑回溯索引) {
//	加入结果集；(通常为xxx.push_back(构成子集的元素))；
//		回溯函数；
//		返回上一层(通常为xxx.pop_back(丢出构成结果的元素)要加入新的构成结果的元素))；
//}

using namespace std;
class Solution {
public:
	string tmp;
	vector<string> res;
	vector<string> board = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

	void DFS(int pos, string& digits) {
		if (pos == digits.size()) {
			res.push_back(tmp);
			return;
		}
		int num = digits[pos] - '0';
		for (int i = 0; i < board[num].size(); i++) {
			tmp.push_back(board[num][i]);
			DFS(pos + 1, digits);
			tmp.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return res;
		DFS(0, digits);
		return res;
	}
};