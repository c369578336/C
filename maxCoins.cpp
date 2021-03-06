// maxCoins.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	vector<vector<int>> rec;
	int coins(vector<int>& nums,int l, int r)
	{
		if (l >= r - 1)
			return 0;
		if (rec[l][r] != -1)
			return rec[l][r];
		for (int i = l+1; i < r; i++)
		{
			int mid = nums[i]*nums[l]*nums[r]+coins(nums, l, i) + coins(nums, i, r);
			rec[l][r] = (int)max(rec[l][r], mid);
		}
		return rec[l][r];
	}
	int maxCoins(vector<int>& nums) {
		vector<int> num = nums;
		int n = nums.size();
		rec.resize(n + 2, vector<int>(n + 2, -1));
		num.insert(num.begin(), 1);
		num.push_back(1);
		return (coins(num, 0, num.size()-1));
	}
};

int main()
{
	vector <int> nums{ 1,2,3,4,5,6 };
	Solution a;
	a.maxCoins(nums);
    return 0;
}

