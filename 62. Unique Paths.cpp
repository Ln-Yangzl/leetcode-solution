#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
	int max = m > n ? m : n;
	int min = m < n ? m : n;
	vector<vector<int>> dp(min + 1, vector<int>(max + 1, 0));
	dp[0][1] = 1;
	for (int i = 1; i <= min; i++) {
		for (int j = 1; j <= max; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[min][max];
}

// Reference https://leetcode.wang/leetCode-62-Unique-Paths.html
int uniquePaths(int m, int n) {
	int N = n + m - 2;
	int k = m - 1;
	long res = 1;
	for (int i = 1; i <= k; i++)
		res = res * (N - k + i) / i;
	return (int)res;
}