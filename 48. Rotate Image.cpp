#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void my_rotate(vector<vector<int>>& matrix) {
	int lenth = matrix.size(), epoch = lenth / 2;
	int little = 0, big = lenth - 1;
	for (int i = 0; i < epoch; i++) {
		for (int j = 0; j < big - little; j++) {
			int temp = matrix[little + j][big];
			matrix[little + j][big] = matrix[little][little + j];
			matrix[little][little + j] = matrix[big - j][little];
			matrix[big - j][little] = matrix[big][big - j];
			matrix[big][big - j] = temp;
		}
		little++;
		big--;
	}
}

//this use much simpler code to solve the problem
void rotate(vector<vector<int>>& matrix) {
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = i + 1; j < matrix.size(); j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}

int main() {
	ifstream infile("test.txt");
	vector<vector<int>> matrix;
	int lenth;
	infile >> lenth;
	for (int i = 0; i < lenth; i++) {
		vector<int> temp;
		for (int j = 0; j < lenth; j++) {
			int num;
			infile >> num;
			temp.push_back(num);
		}
		matrix.push_back(temp);
	}
	rotate(matrix);
	for (int i = 0; i < lenth; i++) {
		for (int j = 0; j < lenth; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
}