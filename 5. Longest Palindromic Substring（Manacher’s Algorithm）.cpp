#include<iostream>
#include<string>
#include<algorithm>

using std::cin;		using std::cout;
using std::endl;	using std::string;
using std::min;

//Ԥ�������ַ���ÿ���ַ�֮����Ϸָ���
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

//������ȡ�������ַ�
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
	//��ǰʶ�����ĺ��ҽ���
	int c = 0, r = 0, lenth = new_str.length();
	//��¼��ÿһ���ַ�Ϊ���ĵĻ��ĳ���
	int* pal_len = new int[lenth];
	//��¼���뾶����Ӧ����
	int max_len = 0, center = 0;

	for (int i = 1; i < lenth - 1; i++)
	{
		//i����c�ĶԳƵ�
		int i_mirror = 2 * c - i;
		if (i < r) {
			pal_len[i] = min(r - i, pal_len[i_mirror]);
		}
		else {
			pal_len[i] = 0;
		}
		//���Լ�����չ
		while (new_str[i + pal_len[i] + 1] == new_str[i - pal_len[i] - 1]) {
			pal_len[i]++;
		}
		//�������ĺͰ뾶
		if (i + pal_len[i] > r) {
			c = i;
			r = i + pal_len[i];
		}
		//��¼�Ƿ�Ϊ��ǰ���
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