#include <iostream>
#include <string>
#include <stack>
	
using std::string;	using std::stack;
using std::cin;		using std::cout;
using std::endl;

bool isComp(char left, char right) {
	return left == '(' && right == ')' || left == '[' && right == ']' || left == '{' && right == '}';
}

bool isValid(string s) {
	stack<char> record;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '[' || s[i] == '{' || s[i] == '(') record.push(s[i]);
		else {
			if (record.empty() || !isComp(record.top(), s[i])) return false;
			record.pop();
		}
	}
	return record.empty();
}
bool isValid(string s) {
	int indexOfLastOpen = -1;
	for (int i = 0; i < s.length(); ++i)
	{
		switch (s[i])
		{
		case '(':
		{
			indexOfLastOpen++;
			s[indexOfLastOpen] = '(';
			break;
		}
		case '{':
		{
			indexOfLastOpen++;
			s[indexOfLastOpen] = '{';
			break;
		}
		case '[':
		{
			indexOfLastOpen++;
			s[indexOfLastOpen] = '[';
			break;
		}
		case ')':
		{
			if (indexOfLastOpen >= 0)
			{
				if (s[indexOfLastOpen] != '(')
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			indexOfLastOpen--;
			break;
		}
		case '}':
		{
			if (indexOfLastOpen >= 0)
			{
				if (s[indexOfLastOpen] != '{')
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			indexOfLastOpen--;
			break;
		}
		case ']':
		{
			if (indexOfLastOpen >= 0)
			{
				if (s[indexOfLastOpen] != '[')
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			indexOfLastOpen--;
			break;
		}
		}
	}

	return indexOfLastOpen >= 0 ? false : true;
}

/*Instead of pushing the left parenthesis in the stack, this can be optimized to push the right parenthesis only and hence a cleaner code.
The time and space complexity is the same though.*/

int main() {
	string s;
	cin >> s;
	cout << isValid(s) << endl;
	return 0;
}