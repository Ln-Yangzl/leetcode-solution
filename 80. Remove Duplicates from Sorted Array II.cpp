#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int removeDuplicates(vector<int>& nums) {
	int i = 0, j = 1;
	bool flag = false;
	while (j < nums.size()) {
		if (nums[i] == nums[j] && flag) {
			j++;
		}
		else {
			flag = nums[i] == nums[j];
			nums[++i] = nums[j++];
		}
	}
	return i + 1;
}