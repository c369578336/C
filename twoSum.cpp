// twoSum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
#include "iostream"
using namespace std;
#include "algorithm"
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector <int> num = nums;
		sort(nums.begin(), nums.end());
		vector <int> ans;
		int length = nums.size();
		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length && nums[i] + nums[j] <= target; j++)
				if (nums[i] + nums[j] == target)
				{
					for (int k = 0; k < length; k++)
						if (num[k] == nums[i] || num[k] == nums[j])
							ans.push_back(k);
				}
		}
		return ans;
	}
};


int main()
{
	Solution a;
	vector <int> num = { 2,3,5,9,7,11 };
	vector <int> ans=a.twoSum(num,10);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
    return 0;
}

