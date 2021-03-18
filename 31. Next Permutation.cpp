#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void nextPermutation(vector<int>& nums) {
	vector<int>::iterator it = --nums.end();
	while (it > nums.begin()) {
		if (*it > *(it - 1)) {
			break;
		}
		it--;
	}
	reverse(it, nums.end());
	vector<int>::iterator greater = it - 1;
	if (it != nums.begin()) {
		while (*greater >= *it) {
			it++;
		}
		swap(*it, *greater);
	}
}

int main() {
	int temp;
	vector<int> nums;
	ifstream infile("test.txt");
	while (infile >> temp) {
		nums.push_back(temp);
	}
	nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
	return 0;
}