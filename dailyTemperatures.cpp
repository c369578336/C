// dailyTemperatures.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector <int> index;
		vector <int> ans(T.size());
		for (int i = 0; i < T.size(); i++)
		{
			if (!index.size())
			{
				index.push_back(i);
			}
			else
			{
				int t = T[i];
				if (t < T[index.back()])
				{
					index.push_back(i);
				}
				else
				{
					while (index.size() && t > T[index.back()])
					{
						ans[index.back()] = i-index.back();
						index.pop_back();
					}
					index.push_back(i);
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution a;
	vector <int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };
	a.dailyTemperatures(T);
    return 0;
}

