// highestPeak.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "stdafx.h"


class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		vector<vector<int>> ans = {};
		int r = isWater.size();
		if (!r) return ans;
		int c = isWater[0].size();
		vector<vector<int>> Water = {};
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (isWater[i][j])
					Water.push_back({ i,j });
			}
		}
		int len = Water.size();
		for (int i = 0; i < r; i++)
		{
			ans.push_back({});
			for (int j = 0; j < c; j++)
			{
				if (isWater[i][j])
					ans[i].push_back(0);
				else
				{
					int max = 99999;
					for (int k = 0; k < len && max>1 ; k++)
					{
						int m = abs(i - Water[k][0]) + abs(j - Water[k][1]);
						if (m < max)
						{
							max = m;
						}
					}
					ans[i].push_back(max);
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution a;
	vector<vector<int>> isWater = {
		{0,0,1},
		{1,0,0},
		{0,0,0}
	};
	a.highestPeak(isWater);
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
