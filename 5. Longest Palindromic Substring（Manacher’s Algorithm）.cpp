#include<iostream>
#include<string>
#include<algorithm>

using std::cin;		using std::cout;
using std::endl;	using std::string;
using std::min;

//预处理，将字符串每个字符之间加上分隔符
string str_pre_process(string& s)
{
	int n = s.length();
	if (n == 0) {
		return "$^";
	}
	string result = "$";
	for (int i = 0; i < n; i++)
	{
		result.push_back('#');
		result.push_back(s[i]);
	}
	result += "#^";
	return result;
}

//后处理，提取出回文字符
string str_refound(string& s, int center, int radius)
{
	string result;
	for (int i = center - radius; i <= center + radius; i++)
	{
		if (s[i] != '#' && s[i] != '$') {
			result += s[i];
		}
	}
	return result;
}

string longestPalindrome(string s)
{
	string new_str = str_pre_process(s);
	//当前识别中心和右界限
	int c = 0, r = 0, lenth = new_str.length();
	//记录以每一个字符为中心的回文长度
	int* pal_len = new int[lenth];
	//记录最大半径及对应中心
	int max_len = 0, center = 0;

	for (int i = 1; i < lenth - 1; i++)
	{
		//i关于c的对称点
		int i_mirror = 2 * c - i;
		if (i < r) {
			pal_len[i] = min(r - i, pal_len[i_mirror]);
		}
		else {
			pal_len[i] = 0;
		}
		//尝试继续拓展
		while (new_str[i + pal_len[i] + 1] == new_str[i - pal_len[i] - 1]) {
			pal_len[i]++;
		}
		//重置中心和半径
		if (i + pal_len[i] > r) {
			c = i;
			r = i + pal_len[i];
		}
		//记录是否为当前最大
		if (max_len < pal_len[i]) {
			max_len = pal_len[i];
			center = i;
		}
	}
	return str_refound(new_str, center, max_len);
}

int main()
{
	string s("abbc");
	cout << longestPalindrome(s) << endl;
	return 0;
}