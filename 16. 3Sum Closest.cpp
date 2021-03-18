#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using std::cin;		using std::cout;
using std::endl;	using std::vector;
using std::ifstream;

int threeSumClosest(vector<int>& nums, int target) {
	std::sort(nums.begin(), nums.end());
	int diff = INT_MAX, sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		int record = nums[i];
		int res = target - record;
		int front = i + 1;
		int back = nums.size() - 1;
		while (front < back) {
			int first = nums[front], second = nums[back];
			int temp = first + second;
			if (temp < res) {
				if (res - temp < diff) {
					diff = res - temp;
					sum = record + temp;
				}
				while (front < back && nums[front] == first) front++;
			}
			else if (temp > res) {
				if (temp - res < diff) {
					diff = temp - res;
					sum = record + temp;
				}
				while (front < back && nums[back] == second) back--;
			}
			else return target;
		}
		while (i + 1 < nums.size() && nums[i + 1] == nums[i])
			i++;
	}
	return sum;
}

int main() {
	vector<int> nums;
	int target;
	ifstream infile("test.txt");
	infile >> target;
	int temp;
	while (infile >>temp)
	{
		nums.push_back(temp);
	}
	cout << threeSumClosest(nums, target) << endl;
	return 0;
}