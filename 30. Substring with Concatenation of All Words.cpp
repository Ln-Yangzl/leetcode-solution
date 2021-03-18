#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

//the hash solution cannot handle the situation 'ababaab' because of the judge func is not robust enough
//bool judge(string target, vector<string>& words, int current = 0) {
//	for (int i = current; i < words.size(); i++) {
//		string::size_type pos;
//		if ((pos = target.find(words[i])) != string::npos) {
//			target[pos] = 'a';
//		}
//		else return false;
//	}
//	return true;
//}
//
typedef map<string, int> map_type;

map_type words_map;
int word_lenth;

void GetMap(const vector<string>& words) {
	pair<map_type::iterator, bool> insert;
	word_lenth = words[0].size();
	for (int i = 0; i < words.size(); i++) {
		insert = words_map.insert(map_type::value_type(words[i], 0));
		insert.first->second++;
	}
}

bool judge(string::iterator begin, string::iterator end) {
	pair<map_type::iterator, bool> insert;
	map_type current_map;
	while (begin != end) {
		insert = current_map.insert(map_type::value_type (string(begin, begin + word_lenth), 0));
		insert.first->second++;
		begin += word_lenth;
		map_type::iterator it = words_map.find(insert.first->first);
		if (it == words_map.end() || insert.first->second > it->second) return false;
	}
	return true;
}

vector<int> findSubstring(string s, vector<string>& words) {
	int lenth = 0, hash = 0;
	GetMap(words);
	vector<int> result;
	for (int i = 0; i < words.size(); i++) {
		lenth += words[i].size();
		for (int j = 0; j < words[i].size(); j++) hash += words[i][j] - 'a';
	}
	if (s.size() < lenth) return result;
	int current = 0;
	for (int i = 0; i < lenth; i++) {
		current += s[i] - 'a';
	}
	if (current == hash && judge(s.begin(), s.begin() + lenth)) {
		result.push_back(0);
	}
	for (int i = 0, j = lenth; j < s.size(); i++, j++) {
		current += ((s[j] - 'a') - (s[i] - 'a'));
		if (current == hash && judge(s.begin() + i + 1, s.begin() + i + 1 + lenth)) {
			result.push_back(i + 1);
		}
	}
	return result;
}

//the solution below is for KMP
//vector<int> findSubstring(string s, vector<string>& words) {
//	vector<vector<int> > KMP_next(words.size(), vector<int>(1, -1));
//	vector<int> pos(words.size(), -1);
//	//get all words' KMP_next arr
//	for (int k = 0; k < words.size(); k++) {
//		for (int i = 0, j = -1; i < words[k].size() - 1;) {
//			for (; j > -1 && words[k][i] != words[k][j];) {
//				j = KMP_next[k][j];
//			}
//			i++; j++;
//			if (words[k][i] == words[k][j]) {
//				KMP_next[k].push_back(KMP_next[k][j]);
//			}
//			else {
//				KMP_next[k].push_back(j);
//			}
//		}
//	}
//}

int main() {
	string s;
	vector<string> words;
	int nums;
	ifstream infile("test.txt");
	infile >> nums >> s;
	for (int i = 0; i < nums; i++) {
		string temp;
		infile >> temp;
		words.push_back(temp);
	}
	vector<int> result = findSubstring(s, words);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
	return 0;
}

/* Reference below */

/*
class Solution {
// The general idea:
// Construct a hash function f for L, f: vector<string> -> int,
// Then use the return value of f to check whether a substring is a concatenation
// of all words in L.
// f has two levels, the first level is a hash function f1 for every single word in L.
// f1 : string -> double
// So with f1, L is converted into a vector of float numbers
// Then another hash function f2 is defined to convert a vector of doubles into a single int.
// Finally f(L) := f2(f1(L))
// To obtain lower complexity, we require f1 and f2 can be computed through moving window.
// The following corner case also needs to be considered:
// f2(f1(["ab", "cd"])) != f2(f1(["ac", "bd"]))
// There are many possible options for f2 and f1.
// The following code only shows one possibility (probably not the best),
// f2 is the function "hash" in the class,
// f1([a1, a2, ... , an]) := int( decimal_part(log(a1) + log(a2) + ... + log(an)) * 1000000000 )
public:
	// The complexity of this function is O(nW).
	double hash(double f, double code[], string &word) {
		double result = 0.;
		for (auto &c : word) result = result * f + code[c];
		return result;
	}
	vector<int> findSubstring(string S, vector<string> &L) {
		uniform_real_distribution<double> unif(0., 1.);
		default_random_engine seed;
		double code[128];
		for (auto &d : code) d = unif(seed);
		double f = unif(seed) / 5. + 0.8;
		double value = 0;

		// The complexity of the following for loop is O(L.size( ) * nW).
		for (auto &str : L) value += log(hash(f, code, str));

		int unit = 1e9;
		int key = (value-floor(value))*unit;
		int nS = S.size(), nL = L.size(), nW = L[0].size();
		double fn = pow(f, nW-1.);
		vector<int> result;
		if (nS < nW) return result;
		vector<double> values(nS-nW+1);
		string word(S.begin(), S.begin()+nW);
		values[0] = hash(f, code, word);

		// Use a moving window to hash every word with length nW in S to a float number,
		// which is stored in vector values[]
		// The complexity of this step is O(nS).
		for (int i=1; i<=nS-nW; ++i) values[i] = (values[i-1] - code[S[i-1]]*fn)*f + code[S[i+nW-1]];

		// This for loop will run nW times, each iteration has a complexity O(nS/nW)
		// So the overall complexity is O(nW * (nS / nW)) = O(nS)
		for (int i=0; i<nW; ++i) {
			int j0=i, j1=i, k=0;
			double sum = 0.;

			// Use a moving window to hash every L.size() continuous words with length nW in S.
			// This while loop will terminate within nS/nW iterations since the increasement of j1 is nW,
			// So the complexity of this while loop is O(nS / nW).
			while(j1<=nS-nW) {
				sum += log(values[j1]);
				++k;
				j1 += nW;
				if (k==nL) {
					int key1 = (sum-floor(sum)) * unit;
					if (key1==key) result.push_back(j0);
					sum -= log(values[j0]);
					--k;
					j0 += nW;
				}
			}
		}
		return result;
	}
};

*/