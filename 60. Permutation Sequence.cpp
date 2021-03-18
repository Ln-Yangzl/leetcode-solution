#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getPermutation(int n, int k) {
	int GroupNum = 1, CurrentGroup = n;
	string res(n, '0');
	vector<int> nums(n, 0);
	for (int i = 1; i <= n; i++) {
		GroupNum *= i;
		nums[i - 1] = i;
	}
	k--;
	GroupNum /= n;
	for (int i = 0; i < n; i++) {
		int GroupIndex = k / GroupNum;
		k %= GroupNum;
		CurrentGroup--;
		GroupNum /= (CurrentGroup == 0 ? 1 : CurrentGroup);
		
		int index = 0, target;
		for (int i = 0; i < n; i++) {
			if (nums[i] != -1) {
				if (index == GroupIndex) {
					target = nums[i];
					nums[i] = -1;
					break;
				}
				else index++;
			}
		}
		res[i] = '0' + target;
	}
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << getPermutation(n, k) << endl;
	return 0;
}