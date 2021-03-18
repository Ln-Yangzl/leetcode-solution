#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	int columns = grid[0].size(), rows = grid.size();
	vector<vector<int>> dp(rows, vector<int>(columns, 0));
	dp[0][0] = grid[0][0];
	// 预处理第一行
	for (int i = 1; i < columns; i++) {
		dp[0][i] = dp[0][i - 1] + grid[0][i];
	}
	for (int i = 1; i < rows; i++) {
		dp[i][0] = dp[i - 1][0] + grid[i][0];
		for (int j = 1; j < columns; j++) {
			dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
		}
	}
	return dp.back().back();
}

// we can use only one row of vector to optimize the space cplx
int minPathSum(vector<vector<int>>& grid) {
	int columns = grid[0].size(), rows = grid.size();
	vector<int> cur(columns, grid[0][0]);
	for (int i = 1; i < columns; i++) {
		cur[i] = cur[i - 1] + grid[0][i];
	}
	for (int i = 1; i < rows; i++) {
		cur[0] += grid[i][0];
		for (int j = 1; j < columns; j++) {
			cur[j] = min(cur[j - 1], cur[j]) + grid[i][j];
		}
	}
	return cur.back();
}