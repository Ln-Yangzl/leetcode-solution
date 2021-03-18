#include <string>
#include <iostream>

using std::string;		using std::cin;
using std::cout;		using std::endl;

int myAtoi(string str) {
	string::size_type i = 0;
	//跳过所有空白和非数字
	while (str[i] == ' ') {
		i++;
		if (i == str.size()) {
			return 0;
		}
	}
	//符号记录，默认无符号为正
	bool sign = false;
	if (str[i] == '-') {
		i++;
		sign = true;
	}
	else if (str[i] == '+') {
		i++;
	}
	else if (str[i] < '0' && str[i]>'9') {
		return 0;
	}
	int result = 0, temp = i;
	while (str[i] >= '0' && str[i] <= '9' && i < str.size())
	{
		int pop = str[i++] - 48;
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) return INT_MAX;
		if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) return INT_MIN;
		if (sign) {
			result = result * 10 - pop;
		}
		else {
			result = result * 10 + pop;
		}
	}
	return result;
}

int main()
{
	string str = "-2147483648";
	cout << myAtoi(str) << endl;
	return 0;
}