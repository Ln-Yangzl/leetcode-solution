#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <unordered_map>

using namespace std;

//this cannot handle all situation, need more powerful hash algrithm
vector<vector<string>> hash_groupAnagrams(vector<string>& strs) {
	map<double, int> pos_map;
	vector<vector<string>> ans;
	for (int i = 0; i < strs.size(); i++) {
		int lenth = strs[i].size();
		double hash = 0.0;
		for (int j = 0; j < lenth; j++) {
			double temp = (strs[i][j] - 'a') * pow(2, (strs[i][j] - 'a'));
			hash += temp;
		}
		hash += lenth;
		auto iter = pos_map.find(hash);
		if (iter != pos_map.end()) {
			ans[iter->second].push_back(strs[i]);
		}
		else {
			pos_map.insert(pair<double, int>(hash, ans.size()));
			ans.push_back(vector<string>(1, strs[i]));
		}
	}
	return ans;
}

//this is actually the same time cmplx with hash method becouse of the usage of counting sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = { 0 };
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};