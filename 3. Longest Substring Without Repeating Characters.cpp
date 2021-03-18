#include<iostream>
#include<string>
#include<algorithm>

using std::string;		using std::find;
using std::cout;		using std::endl;

int lengthOfLongestSubstring(string s) 
{
	int max = 1, count = 0;
	if (s.empty())
		return 0;
	string temp;
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (temp.find(*it) == string::npos)
		{
			temp.push_back(*it);
			count++;
		}
		else
		{
			max = max > count ? max : count;
			temp.erase(temp.begin(), ++find(temp.begin(), temp.end(), *it));
			temp.push_back(*it);
			count = temp.size();
		}
	}
	return max > count ? max : count;
}

int main()
{
	int result = lengthOfLongestSubstring("dvdf");
	cout << result;
	return 0;
}