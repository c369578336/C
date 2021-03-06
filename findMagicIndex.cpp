// findMagicIndex.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	vector <int> num;
	int ans;
	void find(int l, int r)
	{
		int mid = (l + r + 1) / 2;
		if (mid!=r)
		{
			if (num[mid] == mid)
			{
				if (mid < ans || ans == -1)
					ans = mid;
				find(l, mid);
			}
			else 
			{	
				find(l, mid);
				find(mid, r);
			}
		}
	}

	int findMagicIndex(vector<int>& nums) {
		ans = -1;
		num = nums;
		if (nums[0]==0)
			ans = 0;
		find(0, nums.size());
		return ans;
	}
};

int main()
{
	vector <int> nums = { 1, 2, 3, 4, 5 };
	Solution a;
	a.findMagicIndex(nums);
    return 0;
}

