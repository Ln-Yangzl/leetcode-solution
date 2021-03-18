#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
	int start = s.size() - 1, end = s.size() - 1;
	bool flag = false;
	while (start >= 0) {
		if (isalpha(s[start])) {
			flag = true;
			start--;
		}
		else if (!flag) {
			start--;
			end--;
		}
		else break;
	}
	return end - start;
}