// minSubArrayLen.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int ans = INT16_MAX;
		if (nums.empty()) return 0;
		int head=0;
		int end=0;
		int sum =0;
		while (head<=end && end<nums.size())
		{
			sum += nums[end];
			while (sum-nums[head]>=s)
			{
				sum -= nums[head];
				head++;
			}
			if (s<=sum && end - head + 1 < ans)
				ans = end - head + 1;
			end++;
		}
		if (s > sum) return 0;
		else
		return ans;
	}
};

int main()
{
	Solution a;
	vector <int> nums = { 1,1 };
	cout<<a.minSubArrayLen(7, nums);
    return 0;
}

