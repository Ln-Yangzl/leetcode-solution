#include <iostream>
#include <vector>

using std::cin;		using std::cout;
using std::endl;	using std::vector;


int maxArea(vector<int>& height) {
	int m = INT32_MIN;
	for (int i = 0, j = height.size() - 1; i < j;) {
		m = max(m, (j - i) * min(height[i], height[j]));
		height[i] < height[j] ? i++ : j--;
	}
	return m;
}

int main() {
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cout << maxArea(v) << endl;
	return 0;
}