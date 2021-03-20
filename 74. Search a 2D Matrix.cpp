#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size() - 1; i++) {
        // check the first number of current row and next row. If target num is smaller than next row's and equal or greater than current row's,
        // then the target is in current row
        int cur_num = matrix[i][0], nxt_num = matrix[i + 1][0];
        if (target >= cur_num && target < nxt_num) {
            //check current row for target
            bool result = false;
            for (int j = 0; j < matrix[i].size(); j++) {
                result |= (target == matrix[i][j]);
            }
            return result;
        }
    }
    // check the last row
    bool result = false;
    for (int j = 0; j < matrix.back().size(); j++) {
        result |= (target == matrix.back()[j]);
    }
    return result;
}

// to note that the usage of binary search and simpler code
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] < target) {
            row = i;
        }
        else if (matrix[i][0] > target) {
            break;
        }
        else {
            return true;
        }
    }

    return binary_search(matrix[row].begin(), matrix[row].end(), target);
}
