#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using std::cin;		using std::cout;
using std::endl;	using std::vector;
using std::ifstream;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int> > res;

	std::sort(nums.begin(), nums.end());

	for (int i = 0; i + 1 < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			int less = target - nums[i] - nums[j];
			int front = j + 1;
			int back = nums.size() - 1;
			while (front < back) {

				int sum = nums[front] + nums[back];

				// Finding answer which start from number num[i]
				if (sum < less)
					front++;

				else if (sum > less)
					back--;

				else {
					vector<int> quad(4, 0);
					quad[0] = nums[i];
					quad[1] = nums[j];
					quad[2] = nums[front];
					quad[3] = nums[back];
					res.push_back(quad);

					// Processing duplicates of Number 2
					// Rolling the front pointer to the next different number forwards
					while (front < back && nums[front] == quad[2]) front++;

					// Processing duplicates of Number 3
					// Rolling the back pointer to the next different number backwards
					while (front < back && nums[back] == quad[3]) back--;
				}

			}

			// Processing duplicates of Number 1
			while (j + 1 < nums.size() && nums[j + 1] == nums[j])
				j++;
		}
		while (i + 1 < nums.size() && nums[i + 1] == nums[i])
			i++;

	}

	return res;
}

int main() {
	vector<int> nums;
	int target;
	ifstream infile("test.txt");
	infile >> target;
	int temp;
	while (infile >> temp)
	{
		nums.push_back(temp);
	}
	vector<vector<int> > res = fourSum(nums, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}