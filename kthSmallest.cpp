// kthSmallest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		vector <int> ans;
		int* des = new int[n]();
		while (ans.size() < k)
		{
			int min = matrix[n - 1][n - 1] + 1;
			int m = 0;
			for (int i = 0; i < n; i++)
				if (des[i]<n && matrix[i][des[i]] < min)
				{
					min = matrix[i][des[i]];
					m = i;
				}
				des[m]++;
			ans.push_back(min);
		}
		return ans.back();
	}
};

int main()
{
	vector<vector<int>> matrix = {
	{1, 5, 9},
	{ 10, 11, 13 },
	{ 12, 13, 15 },
	};
	Solution a;
	a.kthSmallest(matrix,8);
    return 0;
}

