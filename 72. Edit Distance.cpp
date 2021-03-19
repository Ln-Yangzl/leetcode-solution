#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int minDistance(string word1, string word2) {
   int m = word1.size() + 1, n = word2.size() + 1;
   vector<vector<int>> dp(m, vector<int>(n, 0));
   for (int i = 0; i < n; i++) dp[0][i] = i;
   for (int i = 0; i < m; i++) dp[i][0] = i;
   for (int i = 1; i < m; i++) {
       for (int j = 1; j < n; j++) {
           if (word1[i - 1] == word2[j - 1]) {
               dp[i][j] = dp[i - 1][j - 1];
           }
           else {
               dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
           }
       }
   }
   return dp[m - 1][n - 1];
}

// we can only use one row of vector to record the dp result
int minDistance(string word1, string word2) {
    int m = word1.size() + 1, n = word2.size() + 1;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) dp[i] = i;
    for (int i = 1; i < m; i++) {
        int last = dp[0];
        dp[0] = i; 
        for (int j = 1; j < n; j++) {
            int left_top = last;
            last = dp[j];
            if (word1[i - 1] != word2[j - 1]) {
                left_top++;
            }
            dp[j] = min(left_top, min(dp[j - 1], dp[j]) + 1);
        }
    }
    return dp.back();
}