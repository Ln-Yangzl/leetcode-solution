#include <iostream>
#include <string>
#include <vector>

using namespace std;

// recursion ver
bool pos_verify(vector<string>& current, int x, int y) {
	int n = current.size();
	for (int i = x - 1; i >= 0; i--) {
		if (current[i][y] == 'Q') return false;
	}
	for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
		if (current[i][j] == 'Q') return false;
	}
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
		if (current[i][j] == 'Q') return false;
	}
	return true;
}

void recursion_solver(vector<vector<string>>& ans, vector<string>& current, int n, int row) {
	if (row == n) {
		ans.push_back(current);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (pos_verify(current, row, i)) {
			current[row][i] = 'Q';
			recursion_solver(ans, current, n, row + 1);
			current[row][i] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	string temp(n, '.');
	vector<string> init(n, temp);
	vector<vector<string>> ans;
	recursion_solver(ans, init, n, 0);
	return ans;
}

int main() {
	int n;
	vector<vector<string>> ans;
	cin >> n;
	ans = solveNQueens(n);
	for (int i = 0; i < ans.size(); i++) {
		cout << endl << i << endl;
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}