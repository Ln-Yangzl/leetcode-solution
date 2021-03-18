#include <iostream>
#include <string>

using std::cin;		using std::cout;
using std::endl;	using std::string;

string intToRoman(int num) {
	string result;
	static const int seg[9] = { 1000,500,100,50,10,5,1,0,0 };
	static const char roman[7] = { 'M','D','C','L','X','V','I' };
	for (int i = 0, comp = 2; num; i++) {
		int temp = num / seg[i];
		num %= seg[i];
		while (temp > 0) {
			result.push_back(roman[i]);
			temp--;
		}
		temp = num / (seg[i] - seg[comp]);
		num %= (seg[i] - seg[comp]);
		if (temp == 1) {
			result.push_back(roman[comp]);
			result.push_back(roman[i]);
		}
		if (comp - i == 1) comp += 2;
	}
	return result;
}

//int romanToInt(string s) {
//	static const int seg[9] = { 1000,500,100,50,10,5,1,0,0 };
//	static const char roman[7] = { 'M','D','C','L','X','V','I' };
//	int result = 0;
//	int current = 0, privous = 0;
//	for (string::iterator begin = s.begin(); begin != s.end(); begin++) {
//		for (current = 0; *begin != roman[current]; current++);
//		if (current >= privous) result += seg[current];
//		else {
//			result += (seg[current] - 2 * seg[privous]);
//		}
//		privous = current;
//	}
//	return result;
//}

//reference:
int romanToInt(string s) {
		int res = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			switch (s[i]) {
			case 'M':
					res += 1000; break;
			case 'D':
					res += 500; break;
			case 'C':
					res += 100 * (res >= 500 ? -1 : 1); break;
			case 'L':
					res += 50; break;
			case 'X':
					res += 10 * (res >= 50 ? -1 : 1); break;
			case 'V':
					res += 5; break;
			case 'I':
					res += (res >= 5 ? -1 : 1); break;
			default:
					break;
			}
		}
		return res;
}


int main() {
	int num;
	cin >> num;
	cout << romanToInt(intToRoman(num)) << endl;
	return 0;
}