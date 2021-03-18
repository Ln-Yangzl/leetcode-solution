#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
	if (n == 1) return "1";
	string former = countAndSay(n - 1);
	former.push_back('$');
	string result;
	int count = 0;
	char temp = former[0];
	for (int i = 0; i < former.size(); i++) {
		if (former[i] != temp) {
			result.push_back(count + '0');
			result.push_back(temp);
			count = 0;
			temp = former[i];
		}
		count++;
	}
	return result;
}

int main() {
	string result = countAndSay(4);
	cout << result << endl;
	return 0;
}