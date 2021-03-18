#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) return 0;
	int i = 0, j = 1;
	while (j < nums.size()) {
		if (nums[i] == nums[j]) {
			j++;
		}
		else {
			nums[++i] = nums[j++];
		}
	}
	return i + 1;
}