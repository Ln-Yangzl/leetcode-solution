#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	backtrack(result, candidates, target);
	return result;
}

void backtrack(vector<vector<int>>& result, vector<int>& candidates, int target, int sum = 0, int i = 0) {
	static vector<int> temp;
	if (sum > target) return;
	if (sum == target) result.push_back(temp);
	while (i < candidates.size()) {
		temp.push_back(candidates[i]);
		backtrack(result, candidates, target, sum + candidates[i], i);
		temp.pop_back();
		i++;
	}
}