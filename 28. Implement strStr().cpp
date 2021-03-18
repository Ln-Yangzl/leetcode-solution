#include <iostream>
#include <string>
#include <vector>

using namespace std;

void KMP_next(vector<int>& next, const string& needle) {
	for (int i = 0, j = next[0] = -1; i < needle.size() - 1;) {
		for (; j > -1 && needle[i] != needle[j];) {
			j = next[j];
		}
		i++; j++;
		if (needle[i] == needle[j])
			next[i] = next[j];
		else
			next[i] = j;
	}
}

int strStr(string haystack, string needle) {
	if (needle.empty()) return 0;
	vector<int> next(needle.size());
	KMP_next(next, needle);
	for (int i = 0, j = 0; j < haystack.size();) {
		for (; i > -1 && needle[i] != haystack[j];)
			i = next[i];
		i++; j++;
		if (i >= needle.size()) return j - i;
	}
	return -1;
}