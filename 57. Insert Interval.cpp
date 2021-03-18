#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	if (intervals.empty()) return vector<vector<int>>(1, newInterval);
	int left = newInterval[0], right = newInterval[1];
	vector<vector<int>> res;
	bool insert = false;
	for (int i = 0; i < intervals.size(); i++) {
		if (right < intervals[i][0] && !insert) {
			res.push_back(newInterval);
			insert = true;
			res.push_back(intervals[i]);
		}
		else if (left >= intervals[i][0] && left <= intervals[i][1]) {
			res.push_back(intervals[i]);
			res.back()[1] = max(intervals[i][1], right);
			insert = true;
		}
		else if (right >= intervals[i][0] && right <= intervals[i][1]) {
			if (insert)res.back()[1] = intervals[i][1];
			else {
				res.push_back(newInterval);
				res.back()[1] = max(newInterval[1], intervals[i][1]);
				insert = true;
			}
		}
		else if (intervals[i][1]<left || intervals[i][0]>right) {
			res.push_back(intervals[i]);
		}
	}
	if (!insert) {
		res.push_back(newInterval);
	}
	return res;
}
//simpler
//vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
//	vector<Interval> res;
//	int index = 0;
//	while (index < intervals.size() && intervals[index].end < newInterval.start) {
//		res.push_back(intervals[index++]);
//	}
//	while (index < intervals.size() && intervals[index].start <= newInterval.end) {
//		newInterval.start = min(newInterval.start, intervals[index].start);
//		newInterval.end = max(newInterval.end, intervals[index].end);
//		index++;
//	}
//	res.push_back(newInterval);
//	while (index < intervals.size()) {
//		res.push_back(intervals[index++]);
//	}
//	return res;
//}

//using STL solution 
//vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
//	auto compare = [](const Interval& intv1, const Interval& intv2)
//	{ return intv1.end < intv2.start; };
//	auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
//	auto itr1 = range.first, itr2 = range.second;
//	if (itr1 == itr2) {
//		intervals.insert(itr1, newInterval);
//	}
//	else {
//		itr2--;
//		itr2->start = min(newInterval.start, itr1->start);
//		itr2->end = max(newInterval.end, itr2->end);
//		intervals.erase(itr1, itr2);
//	}
//	return intervals;
//}

int main() {
	int len;
	ifstream infile("test.txt");
	vector<vector<int>> intervals;
	vector<int> newIntervals;
	infile >> len;
	int x, y;
	for (int i = 0; i < len; i++) {	
		vector<int> temp;
		infile >> x >> y;
		temp.push_back(x);
		temp.push_back(y);
		intervals.push_back(temp);
	}
	infile >> x >> y;
	newIntervals.push_back(x);
	newIntervals.push_back(y);
	vector<vector<int>> res = insert(intervals, newIntervals);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0] << ' ' << res[i][1] << endl;
	}
	return 0;
}