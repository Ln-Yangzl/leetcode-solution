#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//this result in duplicates, because this dosent comfirm that after swap, the subarray is still sorted
void DFS(vector<vector<int>>& result, vector<int>& nums, int pos = 0) {
	if (pos == nums.size() - 1) {
		result.push_back(nums);
		return;
	}
	for (int i = pos; i < nums.size(); i++) {
		if (i != pos && (nums[i] == nums[pos] || nums[i] == nums[i - 1])) continue;
		swap(nums[pos], nums[i]);
		DFS(result, nums, pos + 1);
		swap(nums[pos], nums[i]);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	DFS(result, nums);
	return result;
}
//pass by copy avoid duplicates
//void recursion(vector<int> num, int i, int j, vector<vector<int> >& res) {
//    if (i == j - 1) {
//        res.push_back(num);
//        return;
//    }
//    for (int k = i; k < j; k++) {
//        if (i != k && num[i] == num[k]) continue;
//        swap(num[i], num[k]);
//        recursion(num, i + 1, j, res);
//    }
//}
//vector<vector<int> > permuteUnique(vector<int>& num) {
//    sort(num.begin(), num.end());
//    vector<vector<int> >res;
//    recursion(num, 0, num.size(), res);
//    return res;
//}


//this ver can pass because it comfirm that after swap, the subarray is still sorted
//void DFS(vector<vector<int>>& result, vector<int>& nums, int pos = 0) {
//	if (pos == nums.size() - 1) {
//		result.push_back(nums);
//		return;
//	}
//	for (int i = pos; i < nums.size(); i++) {
//		if (i != pos && nums[i] == nums[pos]) continue;
//		swap(nums[pos], nums[i]);
//		DFS(result, nums, pos + 1);
//	}
//	for (int i = nums.size() - 1; i > pos; --i) {
//		swap(nums[pos], nums[i]);
//	}
//}

//vector<vector<int>> permuteUnique(vector<int>& nums) {
//	sort(nums.begin(), nums.end());
//	vector<vector<int>> result;
//	DFS(result, nums);
//	return result;
//}

int main() {
	ifstream infile("test.txt");
	vector<int> nums;
	int temp;
	while (infile >> temp) nums.push_back(temp);
	vector<vector<int>> result = permuteUnique(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}