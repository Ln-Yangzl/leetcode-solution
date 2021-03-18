#include <string>
#include <vector>

using std::string;		using std::vector;

void get_str(vector<string>& result, string& digits, string former, int i = 0) {
	static const char decode[8][5] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	if (i != digits.size()) {
		for (int j = 0, k = digits[i] - '2'; decode[k][j] != '\0'; j++) {
			get_str(result, digits, former + decode[k][j], i + 1);
		}
	}
	else {
		result.push_back(former);
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> result;
	get_str(result, digits, "");
	if (result.size() == 1) result.clear();
	return result;
}

//vector<string> letterCombinations(string digits) {
//	vector<string> result;
//	if (digits.empty()) return vector<string>();
//	static const vector<string> v = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//	result.push_back("");   // add a seed for the initial case
//	for (int i = 0; i < digits.size(); ++i) {
//		int num = digits[i] - '0';
//		if (num < 0 || num > 9) break;
//		const string& candidate = v[num];
//		if (candidate.empty()) continue;
//		vector<string> tmp;
//		for (int j = 0; j < candidate.size(); ++j) {
//			for (int k = 0; k < result.size(); ++k) {
//				tmp.push_back(result[k] + candidate[j]);
//			}
//		}
//		result.swap(tmp);
//	}
//	return result;
//}