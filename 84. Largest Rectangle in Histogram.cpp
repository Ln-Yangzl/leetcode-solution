#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	// record the index of the bar needed
	stack<int> record;
	int i = 0, max_square = 0;
	while (i < heights.size()) {
		if (record.empty() || heights[i] > heights[record.top()]) {
			record.push(i++);
		}
		else {
			int height = heights[record.top()];
			record.pop();
			int left_band = record.empty() ? -1 : record.top();
			int cur_square = (i - left_band - 1) * height;
			max_square = max_square > cur_square ? max_square : cur_square;
		}
	}
	while (!record.empty()) {
		int right_band = heights.size();
		int height = heights[record.top()];
		record.pop();
		int left_band = record.empty() ? -1 : record.top();
		int cur_square = (right_band - left_band - 1) * height;
		max_square = max_square > cur_square ? max_square : cur_square;
	}
	return max_square;
}