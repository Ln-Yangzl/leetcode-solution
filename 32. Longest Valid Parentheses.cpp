#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

/* First version
* cannot handle the situation ()(()
*/
/*
int longestValidParentheses(string s) {
	int max = 0, count = 0, current = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			count++;
		}
		else {
			count--;
			if (count < 0) {
				current = 0;
				count = 0;
			}
			else {
				current += 2;
				max = max > current ? max : current;
			}
		}
	}
	return max;
}*/

int longestValidParentheses(string s) {
	stack<string::iterator> record;
	for (string::iterator it = s.begin(); it != s.end(); it++) {
		if (*it == '(') {
			record.push(it);		//We can push int i instead, considering the index is continuous or not
		}
		else {
			if (record.empty()) continue;
			*record.top() = 'U';
			record.pop();
			*it = 'D';
		}
	}
	int max = 0, count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'U') {
			count += 2;
		}
		else if (s[i] != 'D') {
			max = max > count ? max : count;
			count = 0;
		}
	}
	return max > count ? max : count;
}

int main() {
	string s;
	ifstream infile("test.txt");
	char temp;
	while (infile >> temp) {
		s.push_back(temp);
	}
	cout << longestValidParentheses(s) << endl;
	return 0;
}

/* Reference: DP solution
* My solution uses DP. The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i.

And the DP idea is :

If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.

Else if s[i] is ')'

     If s[i-1] is '(', longest[i] = longest[i-2] + 2

     Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.

   int longestValidParentheses(string s) {
            if(s.length() <= 1) return 0;
            int curMax = 0;
            vector<int> longest(s.size(),0);
            for(int i=1; i < s.length(); i++){
                if(s[i] == ')'){
                    if(s[i-1] == '('){
                        longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                        curMax = max(longest[i],curMax);
                    }
                    else{ // if s[i-1] == ')', combine the previous length.
                        if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                            longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                            curMax = max(longest[i],curMax);
                        }
                    }
                }
                //else if s[i] == '(', skip it, because longest[i] must be 0
            }
            return curMax;
        }

Updated: thanks to Philip0116, I have a more concise solution(though this is not as readable as the above one, but concise):

int longestValidParentheses(string s) {
        if(s.length() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.size(),0);
        for(int i=1; i < s.length(); i++){
            if(s[i] == ')' && i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                    longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                    curMax = max(longest[i],curMax);
            }
        }
        return curMax;
    }
*/

/* Reference: not DP, just open and close, but double-way judge
* int longestValidParentheses(string s) {
        int open = 0;
        int close = 0;
        int maxSize = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                open++;
            else
                close++;
            
            if(open == close){
                maxSize = std::max(maxSize,open+close);
            }
            else if(close > open){
                open = 0;
                close = 0;
            }
        }
        
        open = 0;
        close = 0;
        
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '(')
                open++;
            else
                close++;
            
            if(open == close){
                maxSize = std::max(maxSize,open+close);
            }
            else if(open > close){
                open = 0;
                close = 0;
            }
        }
        
        return maxSize;
    }
*/