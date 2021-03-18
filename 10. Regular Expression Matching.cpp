#include <iostream>
#include <string>
#include <vector>

using std::cout;		using std::endl;
using std::cin;			using std::string;
using std::vector;

//�ݹ�汾,ʱ�䡢�ռ临�ӶȽϸ�
bool RecursIsMatch(string s, string p)
{
	if (p.empty()) {
		return s.empty();
	}
	if (p[1] == '*') {
		return (RecursIsMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.')) && RecursIsMatch(s.substr(1), p);
	}
	else {
		return !s.empty() && (s[0] == p[0] || p[0] == '.') && RecursIsMatch(s.substr(1), p.substr(1));
	}
}


//��̬�滮�汾,ʱ�䡢�ռ临�Ӷ�ΪO(mn)
//�ɲο�https://www.youtube.com/watch?v=l3hda49XcDE&list=PLrmLmBdmIlpuE5GEMDXWf0PWbBD9Ga1lO
bool isMatch(string s, string p)
{
	if (!p.empty() && p[0] == '*') {
		return false;
	}
	int m = s.size(), n = p.size();
	//result[i][j]: if s[0..i - 1] matches p[0..j - 1]
	vector<vector<bool>> result(m + 1, vector<bool>(n + 1, false));
	result[0][0] = true;
	//ֱ�Ӵ�2����ʼ����Ϊ��һ����������*��һ����ƥ��
	for (int i = 2; i <= n; i++) {
		result[0][i] = p[i - 1] == '*' && result[0][i - 2];
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
		{
			if (p[j - 1] != '*') {
				result[i][j] = result[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
			else {
				result[i][j] = result[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && result[i - 1][j];
			}
		}
	}
	return result[m][n];
}

int main() {
	string str1 = "mississippi", str2 = "mis*is*p*.";
	cout << isMatch(str1, str2) << endl;
	return 0;
}