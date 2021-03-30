#include <string>
#include <vector>

using namespace std;
// My idea is to generate the sequence iteratively. For example, when n=3, we can get the result based on n=2.
// 00,01,11,10 -> (000,001,011,010 ) (110,111,101,100). The middle two numbers only differ at their highest bit, while the rest numbers of part two are exactly symmetric of part one.
vector<int> grayCode(int n) {
	static const int pow2[17] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536 };
	vector<int> res(pow2[n], 0);
	for (int i = 0; i < n; i++) {
		for (int j = pow2[i], k = pow2[i] - 1, count = 0; count < pow2[i]; count++, j++, k--) {
			res[j] = res[k] + pow2[i];
		}
	}
	return res;
}

// recursion solution
vector<int> grayCode(int n) {
        if (n == 1){
            return vector<int>{0, 1};
        }
        auto top_half = grayCode(n-1);
        vector<int> bottom_half(top_half);
        reverse(bottom_half.begin(), bottom_half.end());
        for_each(bottom_half.begin(), bottom_half.end(), [=](int &a){a += (1 << (n-1));});
        top_half.insert(top_half.end(), bottom_half.begin(), bottom_half.end());
        return top_half;
}