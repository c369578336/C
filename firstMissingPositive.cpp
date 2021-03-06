// firstMissingPositive.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int max = 0;
		int min = INT16_MAX;
		int ans = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > max)
			{
				max = nums[i];
			}
			if (nums[i] < min && nums[i] >0)
			{
				min = nums[i];
			}
		}
		if (min >= 2) return 1;
		vector <int> bools(max + 2);
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i]>0)
			bools[nums[i]] = 1;
		}
		for (int i = min+1; i <= max+1; i++)
		{
			if (bools[i]==0)
				return i;
		}
		return ans;
	}
};

int main()
{
	Solution a;
	vector <int> nums = { 1, 2, 3, 10, 2147483647, 9 };
	cout<<a.firstMissingPositive(nums);
    return 0;
}

