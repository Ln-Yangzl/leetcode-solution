#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
	int sum = INT_MIN, current = 0;
	for (int i = 0; i < nums.size(); i++) {
		current += nums[i];
		if (current > sum) sum = current;
		if (current < 0) current = 0;
	}
	return sum;
}