#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;


bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    vector<bool> dp(s2.size() + 1, false);
    dp[0] = true;
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0 && j == 0) {
                dp[j] = true;
            }
            else if (i == 0) {
                dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
            }
            else if (j == 0) {
                dp[j] = dp[j] && s1[i - 1] == s3[i - 1];
            }
            else {
                dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1]
                    || dp[j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        }
    }
    return dp.back();
}