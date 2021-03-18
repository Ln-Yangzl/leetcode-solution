#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	// Ԥ�����һ�����һ��
	int flag = 1;
	for (int i = 0; i < obstacleGrid[0].size(); i++) {
		if (obstacleGrid[0][i]) {
			obstacleGrid[0][i] = 0;
			//����һ��ĳ��λ�����ϰ������к��治�ٿɴ�
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
	// �ӵڶ��еڶ��п�ʼ��̬�滮
	for (int i = 1; i < obstacleGrid.size(); i++) {
		for (int j = 1; j < obstacleGrid[i].size(); j++) {
			if (obstacleGrid[i][j]) obstacleGrid[i][j] = 0;
			else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
		}
	}
	return obstacleGrid.back().back();
}