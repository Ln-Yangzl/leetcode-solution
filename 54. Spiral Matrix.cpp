#include <iostream>
#include <fstream>
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

int main() {
	int rows, columns;
	ifstream infile("test.txt");
	infile >> rows >> columns;
	vector<vector<int>> matrix;
	for (int i = 0; i < rows; i++) {
		vector<int> current;
		for (int j = 0; j < columns; j++) {
			int temp;
			infile >> temp;
			current.push_back(temp);
		}
		matrix.push_back(current);
	}
	vector<int> result = spiralOrder(matrix);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
	return 0;
}