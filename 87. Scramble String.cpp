#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <unordered_map>

using namespace std;

// recursion solution, use map to memorize
//bool recur_solver(unordered_map<string, bool>& record, string s1, string s2) {
//    int len = s1.size();
//    if (len == 0) return true;
//    if (len == 1) return s1 == s2;
//    string temp = s1 + s2;
//    bool res = false;
//    if (record.find(temp) != record.end()) return record[temp];
//    else if (s1 == s2) res = true;
//    for (int i = 1; i < len && !res; i++) {
//        //to judge whether the two part is scramble
//        res = res || recur_solver(record, s1.substr(0, i), s2.substr(0, i)) && recur_solver(record, s1.substr(i, len - i), s2.substr(i, len - i));
//        res = res || recur_solver(record, s1.substr(0, i), s2.substr(len - i, i)) && recur_solver(record, s1.substr(i, len - i), s2.substr(0, len - i));
//    }
//    return record[temp] = res;
//}
//
//bool isScramble(string s1, string s2) {
//    unordered_map<string, bool> record;
//    return recur_solver(record, s1, s2);
//}

// DP bottom-up solution
// bool isScramble(string s1, string s2) {
//     int len = s1.size();
//     if (len == 0 || len == 1) return s1 == s2;
//     vector<vector<vector<bool>>> dp(len + 1, vector<vector<bool>>(len, vector<bool>(len, false)));
//     // we check every single charactor
//     for (int i = 0; i < len; i++) {
//         for (int j = 0; j < len; j++) {
//             dp[1][i][j] = s1[i] == s2[j];
//         }
//     }
//     // dp bottom-up check use the information stored in l-1
//     for (int cur_len = 2; cur_len <= len; cur_len++) {
//         for (int i = 0; i <= len - cur_len; i++) {
//             for (int j = 0; j <= len - cur_len; j++) {
//                 for (int k = 1; k < cur_len && !dp[cur_len][i][j]; k++) {
//                     dp[cur_len][i][j] = dp[cur_len][i][j] || (dp[k][i][j] && dp[cur_len - k][i + k][j + k]);
//                     dp[cur_len][i][j] = dp[cur_len][i][j] || (dp[k][i][j + cur_len - k] && dp[cur_len - k][i + k][j]);
//                 }
//             }
//         }
//     }
//     return dp[len][0][0];
// }

// Furhtermore, in many cases, we found we can terminate our recursion early by pruning: 
// i.e. by first checking if s1 and s2 have the same character set before we do recursion: if not, just terminate without recursion. 
// This observation leads us to the following Recursion+cache+pruning version. Here the key of the cache changes to idx1sSize +idx2 + lensSize*sSize;
class Solution {
private:
    bool DP_helper(string &s1, string &s2, int idx1, int idx2, int len, char isS[])
    {
        int sSize = s1.size(),i, j, k, hist[26] , zero_count =0;
        if(isS[(len*sSize+idx1)*sSize+idx2]) return isS[(len*sSize+idx1)*sSize+idx2]==1;
        bool res = false;
        
        fill_n(hist, 26, 0);
        for(k=0; k<len;++k)
        //
        // this is a good way to compare whether two string is equal 
        //
        { // check if s1[idx1:idx1+len-1] and s2[idx2:idx2+len-1] have same characters
            zero_count +=  (0==hist[s1[idx1+k]-'a']) - (0== ++hist[s1[idx1+k]-'a']);
            zero_count +=  (0==hist[s2[idx2+k]-'a']) - (0== --hist[s2[idx2+k]-'a']);
        }
        if(zero_count) {isS[(len*sSize+idx1)*sSize+idx2] = 2; return false;} //if not, return directly
        if(len==1)     {isS[(len*sSize+idx1)*sSize+idx2] = 1; return true;}
        for(k=1;k<len && !res;++k) //otherwise, recursion with cache
        {
            res = res || (DP_helper(s1, s2, idx1, idx2, k, isS) && DP_helper(s1, s2, idx1+k, idx2+k, len-k, isS) );
            res = res || (DP_helper(s1, s2, idx1+len-k, idx2, k, isS) && DP_helper(s1, s2, idx1, idx2+k, len-k, isS) );
        }
        isS[(len*sSize+idx1)*sSize+idx2] = res?1:2;
        return res;
    }
public:
    bool isScramble(string s1, string s2) {
        const int sSize = s1.size();
        if(0==sSize) return true;
        char isS[(sSize+1)*sSize*sSize];
        fill_n(isS, (sSize+1)*sSize*sSize, 0);
        return DP_helper(s1, s2, 0, 0, sSize, isS);
    }
};