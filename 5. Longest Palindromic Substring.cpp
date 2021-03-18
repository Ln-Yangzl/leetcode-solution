#include<iostream>
#include<string>

using std::cin;		using std::cout;
using std::endl;	using std::string;

void checkPalindrome(const string& s, int low, int high, int& start, int& max_len)
{
	while (low >= 0 && high < s.size() && s[low] == s[high])
	{
		if (high - low + 1 > max_len)
		{
			max_len = high - low + 1;
			start = low;
		}
		--low;
		++high;
	}
}

string longestPalindrome(string s)
{
	int max_len = 1;
	int start = 0;

	for (int i = 1; i < s.size(); i++)
	{
		checkPalindrome(s, i - 1, i, start, max_len);   /* Even */
		checkPalindrome(s, i - 1, i + 1, start, max_len);   /* Odd */
	}
	return s.substr(start, max_len);
}


int main()
{
	string s("abacab");
	cout << longestPalindrome(s) << endl;
	return 0;
}