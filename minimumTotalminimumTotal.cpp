// minimumTotalminimumTotal.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class Solution {
public:
	int min(int a, int b)
	{
		if(a > b) return b;
		else
		{
			return a;
		}
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		int N = triangle.size();
		if (N == 0) return 0;
		for (int i = N-2; i >=0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return  triangle[0][0];
	}
};

int main()
{
	Solution a;
	vector<vector<int>> arr=
	{
		{2 },
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};
	a.minimumTotal(arr);
    return 0;
}

