class Solution {
public:
	vector<string> res;
	// 什么时候选左括号： 左括号的的数量 > 0
	// 什么时候选右括号： 右括号的数量>0 &&右括号的数量！=左括号的数量
	vector<string> generateParenthesis(int n) {
		string Path;
		generateParenthesisHelper(Path, n, n);
		return res;
	}

	void generateParenthesisHelper(string& Path, int left, int right) {
		// 括号选完了 直接放入结果数组中 返回
		if (left == 0 && right == 0) {
			res.push_back(Path);
			return;
		}
		//还有左括号，先写左括号
		if (left > 0) {
			Path.push_back('(');
			generateParenthesisHelper(Path, left - 1, right);
			Path.pop_back();
		}
		//还有右括号
		if (right > 0 && left != right) {
			Path.push_back(')');
			generateParenthesisHelper(Path, left, right - 1);
			Path.pop_back();
		}
	}
};