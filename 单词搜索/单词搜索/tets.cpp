#include<iostream>
#include<vector>
#include<string>

using namespace std;

//C++ DFS backtracking µÄËã·¨
class Solution {
public:
	bool isOut(int r, int c, int rows, int cols) {
		return c < 0 || c >= cols || r < 0 || r >= rows;
	}

	bool DFS(vector<vector<char>> &board, int r, int c, string &word, int start) {
		if (start >= word.size())
			return true;
		if (isOut(r, c, board.size(), board[0].size()) || word[start] != board[r][c])
			return false;

		int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
		char tmp = board[r][c];
		board[r][c] = '.';
		for (int i = 0; i < 4; ++i) {
			if (DFS(board, r + dx[i], c + dy[i], word, start + 1))
				return true;
		}
		board[r][c] = tmp;
		return false;
	}

	bool exist(vector<vector<char> > &board, string word) {
		int rows = board.size(), cols = board[0].size();
		for (int r = 0; r < rows; ++r)
			for (int c = 0; c < cols; ++c) {
				if (board[r][c] == word[0])
					if (DFS(board, r, c, word, 0))
						return true;
			}
		return false;
	}
};

int main(){
	
	system("pause");
	return 0;
}