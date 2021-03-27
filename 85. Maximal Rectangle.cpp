#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// The DP solution proceeds row by row, starting from the first row. Let the maximal rectangle area at row i and column j be computed by [right(i,j) - left(i,j)]*height(i,j).

// All the 3 variables left, right, and height can be determined by the information from previous row, and also information from the current row. So it can be regarded as a DP solution. The transition equations are:

//     left(i,j) = max(left(i-1,j), cur_left), cur_left can be determined from the current row

//     right(i,j) = min(right(i-1,j), cur_right), cur_right can be determined from the current row

//     height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1';

//     height(i,j) = 0, if matrix[i][j]=='0'

// The code is as below. The loops can be combined for speed but I separate them for more clarity of the algorithm.

// reference : https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) return 0;
    int m = matrix.size(), n = matrix[0].size();
    int max_area = 0;
    vector<int> left(n, 0), right(n, n), height(n, 0);
    for (int i = 0; i < m; i++) {
        // find the left bond and height bond
        int cur_left = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                // use max to garentee forming up to a rectangle
                left[j] = max(cur_left, left[j]);
                height[j]++;
            }
            else {
                cur_left = j + 1;
                left[j] = 0;
                height[j] = 0;
            }
        }
        // find right bond
        int cur_right = n;
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == '1') {
                // use min to garentee forming up to a rectangle
                right[j] = min(cur_right, right[j]);
            }
            else {
                cur_right = j;
                right[j] = n;
            }
        } 
        // caculate all area and store the max
        for (int j = 0; j < n; j++) {
            max_area = max(max_area, (right[j] - left[j]) * height[j]);
        }
    }
    return max_area;
    }