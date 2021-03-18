#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

//DFS recursion will lead to TLE
bool DFS_varify(vector<int>& nums, int current) {
	if (current >= nums.size() - 1) return true;
	for (int i = 0; i < nums[current]; i++) {
		bool temp = DFS_varify(nums, current + nums[current] - i);
		if (temp) return true;
	}
	return false;
}

//simpler
bool canJump(vector<int>& nums) {
	int i = 0;
	for (int reach = 0; i < nums.size() && i <= reach; ++i)
		reach = max(i + nums[i], reach);
	return i == nums.size();
}

bool canJump(vector<int>& nums) {
	int left = 0, right = nums[0], last = nums.size() - 1;
	while (right < last) {
		int max = 0;
		for (int i = left; i <= right; i++) {
			int new_pos = i + nums[i];
			max = max > new_pos ? max : new_pos;
		}
		left = right;
		right = max;
		if (left == right) return false;
	}
	return true;
}

//bool canJump(vector<int>& nums) {
//	typedef pair<int, int> node;
//	stack<node> record;
//	int pos = nums[0];
//	record.push(node(0, nums[0] - 1));
//	while (!record.empty()) {
//		if (pos >= nums.size()) return true;
//		if (nums[pos] == 0) {
//			while (record.top().second == 0) record.pop();
//			int stride = record.top().second;
//			pos = record.top().first;
//			record.pop();
//			record.push(node(pos, stride - 1));
//			pos += stride;
//		}
//	}
//
//}

int main() {
	ifstream infile("test.txt");
	int temp;
	vector<int> nums;
	while (infile >> temp) nums.push_back(temp);
	cout << canJump(nums) << endl;
	return 0;
}