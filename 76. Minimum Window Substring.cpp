#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// reference: https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems

string minWindow(string s, string t) {
    vector<int> m(128, 0);
    for (auto i : t) m[i]++;
    int count = t.size(), start = 0, end = 0, minwid = INT_MAX, start_pos = 0;
    while (end < s.size()) {
        // find the end pos to make the substring valid
        // if the char is not in t, the number will be negative, this make sure the correctness of 'count++'
        if (m[s[end++]]-- > 0) {
            count--;
        }
        // if now the substring is valid
        while (count == 0) {
            // record it
            int cur = end - start;
            if (cur < minwid) {
                minwid = cur;
                start_pos = start;
            }
            // move the left bound to find the next valid substring
            m[s[start]]++;
            // the correction of count++ is guaranteed 
            if (m[s[start]] > 0) {
                count++;
            }
            start++;
        }
    }
    if (minwid != INT_MAX) return s.substr(start_pos, minwid);
    return "";
}