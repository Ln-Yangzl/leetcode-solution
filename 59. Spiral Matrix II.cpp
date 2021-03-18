#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() == 0) return vector<int>();
	int height = matrix.size(), width = matrix[0].size();
	int smaller = height < width ? height : width;
	int total = height * width;
	vector<int> result(total, 0);
	int count = 0;
	for (int i = 0; i < width; i++) result[count++] = matrix[0][i];
	int y = width - 1, x = 0, flag = 1;
	for (int i = 1; count != total; i++) {
		for (int j = 0; j < height - i; j++) {
			x += flag;
			result[count++] = matrix[x][y];
		}
		for (int j = 0; j < width - i; j++) {
			y -= flag;
			result[count++] = matrix[x][y];
		}
		flag = -flag;
	}
	return result;
}

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> res(n, vector<int>(n, 0));
	int count = 1, total = n * n;
	for (int i = 0; i < n; i++) res[0][i] = count++;
	int y = n - 1, x = 0, flag = 1;
	for (int i = 1; count <= total; i++) {
		for (int j = 0; j < n - i; j++) {
			x += flag;
			res[x][y] = count++;
		}
		for (int j = 0; j < n - i; j++) {
			y -= flag;
			res[x][y] = count++;
		}
		flag = -flag;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> res = generateMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}