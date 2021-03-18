#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate(vector<string>& result, string temp, int left, int right, int n) {
	if (right == n) {
		result.push_back(temp);
		return;
	}
	if (left < n) generate(result, temp + '(', left + 1, right, n);
	if (right < left) generate(result, temp + ')', left, right + 1, n);
}

vector<string> generateParenthesis(int n) {
	vector<string> result;
	generate(result, "", 0, 0, n);
	return result;
}

int main() {
	vector<string> result = generateParenthesis(3);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
	return 0;
}