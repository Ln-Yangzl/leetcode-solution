#include <iostream>
#include <vector>
#include <string>

using std::cin;		using std::cout;
using std::endl;	using std::string;
using std::vector;

string longestCommonPrefix(vector<string>& strs) {
	string prefix = "";
	if (strs.empty()) return prefix;
	for (int i = 0; i < strs[0].size(); i++) {
		char ch = strs[0][i];
		for (int j = 1; j < strs.size(); j++) {
			if (ch != strs[j][i]) return prefix;
		}
		prefix.push_back(ch);
	}
	return prefix;
}
