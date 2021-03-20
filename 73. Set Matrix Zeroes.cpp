#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

// using map to store the rows and cols that need to set to zero
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    map<int, bool> row, column;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                column[j] = true;
            }
        }
    }
    for (map<int, bool>::iterator it = row.begin(); it != row.end(); it++) {
        int i = it->first;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    for (map<int, bool>::iterator it = column.begin(); it != column.end(); it++) {
        int i = it->first;
        for (int j = 0; j < m; j++) {
            matrix[j][i] = 0;
        }
    }
}

//just using the first row and col to store the info needed, making the space cplx to be O(1)
void setZeroes(vector<vector<int> >& matrix) {
    // because of col0 and row0 share the position (0,0) , so we let (0,0) to be row0 and use another variable col0 instead
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}