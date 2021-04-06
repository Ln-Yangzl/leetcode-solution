#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int numTrees(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int len = 1; len <= n; len++) {
		for (int root = 1; root <= len; root++) {
			/*int left = root - 1, right = len - root;*/
			dp[len] += dp[root - 1] * dp[len - root];
		}
	}
	return dp[n];
}