#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& candidates, int index, int res) {
	static vector<int> temp;
	if (res == 0) {
		result.push_back(temp);
		return;
	}
	if (index == candidates.size() || res < candidates[index]) return;
	
	temp.push_back(candidates[index++]);
	backtrack(result, candidates, index, res - candidates[index - 1]);
	temp.pop_back();
	while (index != candidates.size() && candidates[index - 1] == candidates[index]) index++;
	backtrack(result, candidates, index, res);
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	sort(candidates.begin(), candidates.end());
	backtrack(result, candidates, 0, target);
	return result;
}


int main() {
	vector<int> candidates;
	int target;
	ifstream infile("test.txt");
	infile >> target;
	int temp;
	while (infile >> temp) candidates.push_back(temp);
	vector<vector<int>> result = combinationSum2(candidates, target);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}