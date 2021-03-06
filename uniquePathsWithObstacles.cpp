// uniquePathsWithObstacles.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> ans(m);
		int flag = 1;
		for (int i = 0; i < m; i++)
		{
			ans[i].resize(n);
			if (obstacleGrid[i][0])
				flag = 0;
			if (flag)
			ans[i][0] = 1;
			else
			{
				ans[i][0] = 0;
			}
		}
		flag = 1;
		for (int i = 0; i < n; i++)
		{
			if (obstacleGrid[0][i])
				flag = 0;
			if (flag)
				ans[0][i] = 1;
			else
			{
				ans[0][i] = 0;
			}
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (!obstacleGrid[i][j])
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
			}
		}
		return ans[m - 1][n - 1];
	}
};

int main()
{
	vector <vector<int>> arr=
	{
		{0,0,0},
		{0, 1,0},
		{0, 0,0}
	};
	Solution a;
	cout <<a.uniquePathsWithObstacles(arr);
    return 0;
}

