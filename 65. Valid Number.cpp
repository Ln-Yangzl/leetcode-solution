#include <iostream>
#include <string>

using namespace std;

//  finite automaton solution
bool isNumber(string s)
{
    int stage = 0;
    bool num_flag = false, dot_flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        switch (stage)
        {
        case 0:
            if (s[i] == '+' || s[i] == '-')
            {
                stage = 1;
            }
            else if (isdigit(s[i]) || s[i] == '.') {
                stage = 2;
            }
            else
                return false;
            break;
        case 1:
            if (isdigit(s[i]) || s[i] == '.')
            {
                stage = 2;
            }
            else
                return false;
            break;
        case 2:
            if (isdigit(s[i])|| s[i] == '.' && !dot_flag) {
                stage = 2;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                stage = 3;
                if (!num_flag) return false;
                num_flag = false;
            }
            else
                return false;
            break;
        case 3:
            if (isdigit(s[i])) {
                stage = 5;
            }
            else if (s[i] == '+' || s[i] == '-') {
                stage = 4;
            }
            else
                return false;
            break;
        case 4:
            if (isdigit(s[i])) {
                stage = 5;
            }
            else
                return false;
            break;
        case 5:
            if (isdigit(s[i])) {
                stage = 5;
            }
            else
                return false;
            break;
        default:
            break;
        }
        num_flag |= isdigit(s[i]);
        dot_flag |= s[i] == '.';
    }
    return num_flag;
}

// The idea is pretty straightforward. A valid number is composed of the significand and the exponent (which is optional). As we go through the string, do the following things one by one:

//     skip the leading whitespaces;
//     check if the significand is valid. To do so, simply skip the leading sign and count the number of digits and the number of points. A valid significand has no more than one point and at least one digit.
//     check if the exponent part is valid. We do this if the significand is followed by 'e'. Simply skip the leading sign and count the number of digits. A valid exponent contain at least one digit.
//     skip the trailing whitespaces. We must reach the ending 0 if the string is a valid number.

// =======================================================

bool isNumber(const char *s) 
{
    int i = 0;
    
    // skip the whilespaces
    for(; s[i] == ' '; i++) {}
    
    // check the significand
    if(s[i] == '+' || s[i] == '-') i++; // skip the sign if exist
    
    int n_nm, n_pt;
    for(n_nm=0, n_pt=0; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
        s[i] == '.' ? n_pt++:n_nm++;       
    if(n_pt>1 || n_nm<1) // no more than one point, at least one digit
        return false;
    
    // check the exponent if exist
    if(s[i] == 'e') {
        i++;
        if(s[i] == '+' || s[i] == '-') i++; // skip the sign
        
        int n_nm = 0;
        for(; s[i]>='0' && s[i]<='9'; i++, n_nm++) {}
        if(n_nm<1)
            return false;
    }
    
    // skip the trailing whitespaces
    for(; s[i] == ' '; i++) {}
    
    return s[i]==0;  // must reach the ending 0 of the string
}

int main(){
    string s;
    cin >> s;
    cout << isNumber(s) << endl;
    return 0;
}