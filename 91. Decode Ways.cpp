#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

inline bool isInrange(int a, int b) {
	return a == '1' || (a == '2' && b >= '0' && b <= '6');
}
// use dp solution iteratier from back
int numDecodings(string s) {
	// use prev and pprev to record the number of ways the i+1 and i+2 pos substring has
	int last = s.size() - 1;
	int pprev = s[last--] != '0';
	if (s.size() == 1) return pprev;
	int prev = (s[last] != '0' & pprev) + isInrange(s[last], s[last + 1]);
	for (int i = last - 1; i >= 0; i--) {
		int cur = 0;
		// s[i] can be decoded
		if (s[i] != '0') {
			cur += prev;
		}
		// s[i] and s[i+1] can be decoded
		if (isInrange(s[i], s[i + 1])) {
			cur += pprev;
		}
		swap(cur, prev);
		swap(cur, pprev);
	}
	return prev;
}