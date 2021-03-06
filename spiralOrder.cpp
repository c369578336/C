// spiralOrder.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int line = matrix.size();
		vector <int> ans;
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return {};
		}
		int col = matrix[0].size();
		int m = line-1 ;//行上限
		int n = col-1 ;//列上限
		int x = 0;//行下限
		int y = 0;//列下限
		while (ans.size()<line*col)
		{
			for (int i = y; i <= n; i++)
				ans.push_back(matrix[x][i]);
			x++;;//当前行输出 下限+1
			if (x > m) break;
			for (int j=x;j<=m;j++)
				ans.push_back(matrix[j][n]);
			n--;//最高列输出 上限-1
			if (y > n) break;
			for (int i = n; i>=y; i--)
				ans.push_back(matrix[m][i]);
			m--; //上限行输出 上限-1
			if (x > m) break;
			for (int j = m; j>=x; j--)
				ans.push_back(matrix[j][y]);
			y++;
			if (y > n) break;
		}
		return ans;
	}
};

int main()
{
	Solution a;
	vector<vector<int>> matrix = { {1} };
	a.spiralOrder(matrix);
    return 0;
}

