#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	if (nums.empty()) return 0;
	int i = 0, j = 0;
	while (j < nums.size()) {
		if (nums[j] == val) {
			j++;
		}
		else {
			nums[i++] = nums[j++];
		}
	}
	return i;
}