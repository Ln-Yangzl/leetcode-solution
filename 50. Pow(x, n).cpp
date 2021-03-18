#include <iostream>
#include <stack>

using namespace std;

double myPow(double x, int n) {
	if (n == 0) return 1.0;
	int temp = abs(n);
	double res = 1.0;
	while (temp > 0) {
		if (temp & 1) res = res * x;
		x *= x;
		temp >>= 1;
	}
	return n > 0 ? res : 1.0 / res;
}

int main() {
	double x;
	int n;
	cin >> x >> n;
	cout << myPow(x, n);
	return 0;
}