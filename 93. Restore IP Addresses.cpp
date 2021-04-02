#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool valid(string& s, int left, int right) {
	if (s[left] == '0'&&left != right - 1) return false;
	int count = 0;
	while (left < right) {
		count *= 10;
		count += s[left++] - '0';
	}
	if (count >= 0 && count <= 255) return true;
	return false;
}

void recurion_helper(vector<string>& res, string& s, string& cur, int left, int count) {
	if (count == 4) {
		if (left == s.size()) {
			res.push_back(cur.substr(1, cur.size() - 1));
		}
		return;
	}
	cur[left + count] = '.';
	for (int i = 1; i <= 3; i++) {
		if (valid(s, left, left + i)) {
			for (int j = 0; j < i; j++) {
				cur[left + count + j + 1] = s[left + j];
			}
			recurion_helper(res, s, cur, left + i, count + 1);
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> res;
	string cur(s.size() + 4, '0');
	recurion_helper(res, s, cur, 0, 0);
	return res;
}