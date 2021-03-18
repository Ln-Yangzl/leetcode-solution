#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	// 预处理第一行与第一列
	int flag = 1;
	for (int i = 0; i < obstacleGrid[0].size(); i++) {
		if (obstacleGrid[0][i]) {
			obstacleGrid[0][i] = 0;
			//若第一行某个位置有障碍物，则该行后面不再可达
			flag = 0;
		} 
		else {
			obstacleGrid[0][i] = flag;;
		}	
	}
	for (int i = 1; i < obstacleGrid.size(); i++) {
		if (obstacleGrid[i][0]) obstacleGrid[i][0] = 0;
		else obstacleGrid[i][0] = obstacleGrid[i-1][0];
	}
	// 从第二行第二列开始动态规划
	for (int i = 1; i < obstacleGrid.size(); i++) {
		for (int j = 1; j < obstacleGrid[i].size(); j++) {
			if (obstacleGrid[i][j]) obstacleGrid[i][j] = 0;
			else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
		}
	}
	return obstacleGrid.back().back();
}