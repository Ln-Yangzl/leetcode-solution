#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
	if (dividend == INT_MIN && divisor == -1) return INT_MAX;
	bool sign = dividend > 0 == divisor > 0;
	dividend = dividend > 0 ? -dividend : dividend;		//转为负数避免负转正的溢出
	divisor = divisor > 0 ? -divisor : divisor;
	int result = 0;
	while (dividend <= divisor) {
		int temp = 1, cur_sum = divisor << 1, prev_sum = divisor;
		while (dividend <= cur_sum && cur_sum < prev_sum) {
			prev_sum = cur_sum;
			cur_sum <<= 1;
			temp <<= 1;
		}
		result += temp;
		dividend -= prev_sum;
	}
	return sign ? result : -result;
}

int main() {
	cout << divide(7, -3) << endl;
	return 0;
}