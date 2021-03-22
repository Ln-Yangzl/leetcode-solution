#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void recursion(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int pos, int start, int end) {
	if (pos == temp.size()) {
		res.push_back(temp);
		return;
	}
	for (int i = start; i < end; i++) {
		temp[pos] = nums[i];
		recursion(res, temp, nums, pos + 1, i + 1, end);
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	int k = nums.size();
	for (int i = 0; i <= k; i++) {
		vector<int> temp(i, 0);
		recursion(res, temp, nums, 0, 0, nums.size());
	}
	return res;
}