#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& x, const vector<int>& y) {
	return x[0] < y[0];
}

//cannot handle unsorted situation
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), comp);
	vector<int> current = intervals[0];
	vector<vector<int>> result;
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i][0] <= current[1]) {
			current[1] = intervals[i][1] > current[1] ? intervals[i][1] : current[1];
		}
		else {
			result.push_back(current);
			current = intervals[i];
		}
	}
	result.push_back(current);
	return result;
}

int main() {
	int n;
	vector<vector<int>> intervals;
	ifstream infile("test.txt");
	infile >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		vector<int> temp;
		infile >> x >> y;
		temp.push_back(x);
		temp.push_back(y);
		intervals.push_back(temp);
	}
	vector<vector<int>> res = merge(intervals);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0] << ' ' << res[i][1] << endl;
	}
	return 0;
}