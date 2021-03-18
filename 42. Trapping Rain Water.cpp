#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//找出最大的一个高度，两边开始减去没装水的
int trap(vector<int>& height) {
	if (height.size() == 0) return 0;
	int pos = 0, max = 0;
	for (size_t i = 0; i < height.size(); i++) {
		if (height[i] > max) {
			max = height[i];
			pos = i;
		}
	}
	int water = max * height.size();
	for (int left = 0, current_max = 0, max_pos = 0; left <= pos; left++) {
		if (height[left] > current_max) {
			current_max = height[left];
			max_pos = left;
		}
		water -= (height[left] + (max - current_max));
	}
	for (int right = height.size() - 1, current_max = 0, max_pos = 0; right > pos; right--) {
		if (height[right] > current_max) {
			current_max = height[right];
			max_pos = right;
		}
		water -= (height[right] + (max - current_max));
	}
	return water;
}

//直接考虑，从左右开始
int trap(int A[], int n) {
	int left = 0; int right = n - 1;
	int res = 0;
	int maxleft = 0, maxright = 0;
	while (left <= right) {
		if (A[left] <= A[right]) {
			if (A[left] >= maxleft) maxleft = A[left];
			else res += maxleft - A[left];
			left++;
		}
		else {
			if (A[right] >= maxright) maxright = A[right];
			else res += maxright - A[right];
			right--;
		}
	}
	return res;
}

int main() {
	ifstream infile("test.txt");
	int temp;
	vector<int> height;
	while (infile >> temp) height.push_back(temp);
	cout << trap(height) << endl;
	return 0;
}