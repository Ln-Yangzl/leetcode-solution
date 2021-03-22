#include <iostream>
#include <vector>

using namespace std;

void recursion(vector<vector<int>>& res, vector<int>& temp, int pos, int start, int end) {
	if (pos == temp.size()) {
		res.push_back(temp);
		return;
	}
	for (int i = start; i <= end; i++) {
		temp[pos] = i;
		recursion(res, temp, pos + 1, i + 1, end);
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> temp(k, 0);
	recursion(res, temp, 0, 1, n);
	return res;
}