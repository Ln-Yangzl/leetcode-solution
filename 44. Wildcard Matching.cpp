#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//bool match(string::iterator sbegin, string::iterator send, string::iterator pbegin, string::iterator pend) {
//	if (sbegin == send || pbegin == pend) {
//		while (pbegin != pend && *pbegin == '*') pbegin++;
//		return sbegin == send && pbegin == pend;
//	} 
//	if (*pbegin == '?') return match(++sbegin, send, ++pbegin, pend);
//	if (*pbegin == '*') {
//		while (*pbegin == '*' || *pbegin == '?') {
//			pbegin++;
//			if (*pbegin == '?' && ++sbegin == send) return match(sbegin, send, pbegin + 1, pend);
//			if (pbegin == pend) return true;
//		} 
//		bool result = false;
//		while (sbegin != send) {
//			if (*sbegin == *pbegin) {
//				result |= match(sbegin + 1, send, pbegin + 1, pend);
//			}
//			sbegin++;
//		}
//		return result;
//	}
//	if (*pbegin == *sbegin) return match(++sbegin, send, ++pbegin, pend);
//	else return false;
//}
//
//bool isMatch(string s, string p) {
//	return match(s.begin(), s.end(), p.begin(), p.end());
//}

bool isMatch(string s, string p) {
	string::size_type m = s.size(), n = p.size();
	vector<vector<bool>> result(m + 1, vector<bool>(n + 1, false));
	result[0][0] = true;
	for (size_t i = 1; i <= n; i++) {
		result[0][i] = p[i - 1] == '*' && result[0][i - 1];
	}
	for (size_t i = 1; i <= m; i++) {
		for (size_t j = 1; j <= n; j++) {
			if (p[j - 1] != '*') {
				result[i][j] = result[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
			}
			else {
				result[i][j] = result[i][j - 1] || result[i - 1][j - 1] || result[i - 1][j];
			}
		}
	}
	return result[m][n];
}

bool isMatch(const char* s, const char* p) {
	const char* star = NULL;
	const char* ss = s;
	while (*s) {
		//advancing both pointers when (both characters match) or ('?' found in pattern)
		//note that *p will not advance beyond its length 
		if ((*p == '?') || (*p == *s)) { s++; p++; continue; }

		// * found in pattern, track index of *, only advancing pattern pointer 
		if (*p == '*') { star = p++; ss = s; continue; }

		//current characters didn't match, last pattern pointer was *, current pattern pointer is not *
		//only advancing pattern pointer
		if (star) { p = star + 1; s = ++ss; continue; }

		//current pattern pointer is not star, last patter pointer was not *
		//characters do not match
		return false;
	}

	//check for remaining characters in pattern
	while (*p == '*') { p++; }

	return !*p;
}

int main() {
	string s, p;
	ifstream infile("test.txt");
	infile >> s >> p;
	cout << isMatch(s, p) << endl;
	return 0;
}