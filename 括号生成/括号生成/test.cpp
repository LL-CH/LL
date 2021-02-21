class Solution {
public:
	vector<string> res;
	// ʲôʱ��ѡ�����ţ� �����ŵĵ����� > 0
	// ʲôʱ��ѡ�����ţ� �����ŵ�����>0 &&�����ŵ�������=�����ŵ�����
	vector<string> generateParenthesis(int n) {
		string Path;
		generateParenthesisHelper(Path, n, n);
		return res;
	}

	void generateParenthesisHelper(string& Path, int left, int right) {
		// ����ѡ���� ֱ�ӷ����������� ����
		if (left == 0 && right == 0) {
			res.push_back(Path);
			return;
		}
		//���������ţ���д������
		if (left > 0) {
			Path.push_back('(');
			generateParenthesisHelper(Path, left - 1, right);
			Path.pop_back();
		}
		//����������
		if (right > 0 && left != right) {
			Path.push_back(')');
			generateParenthesisHelper(Path, left, right - 1);
			Path.pop_back();
		}
	}
};