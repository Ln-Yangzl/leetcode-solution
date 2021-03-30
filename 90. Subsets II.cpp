#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int dupli_start = 0;
	vector<vector<int>> res(1,vector<int>());
	for (int i = 0; i < nums.size(); i++) {
		int current_size = res.size();
		int start = dupli_start;
		if (i == 0 || nums[i] != nums[i - 1]) {
			res.push_back(vector<int>(1, nums[i]));
			start = 0;
		}
		dupli_start = current_size;
		while (start < current_size) {
			vector<int> temp(res[start++]);
			temp.push_back(nums[i]);
			res.push_back(move(temp));
		}
	}
	res.push_back(vector<int>());
	return res;
}