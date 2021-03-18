#include <iostream>
#include <vector>

using namespace std;

void recursion_solver(vector<bool>& col, vector<bool>& md, vector<bool>& sd, int& count, int row, int n) {
	if (row == n) {
		count++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!col[i] && !md[n - row + i - 1] && !sd[row + i]) {
			col[i] = md[n - row + i - 1] = sd[row + i] = true;
			recursion_solver(col, md, sd, count, row + 1, n);
			col[i] = md[n - row + i - 1] = sd[row + i] = false;
		}
	}
}

int totalNQueens(int n) {
	vector<bool> col(n, false);
	vector<bool> md(2 * n - 1, false);
	vector<bool> sd(2 * n - 1, false);
	int count = 0;
	recursion_solver(col, md, sd, count, 0, n);
	return count;
}

int main() {
	int n;
	cin >> n;
	int count = totalNQueens(n);
	cout << count << endl;
	return 0;
}