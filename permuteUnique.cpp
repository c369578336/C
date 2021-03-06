// permuteUnique.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class Solution {
	vector<int> vis;

public:
	void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
		if (idx == nums.size()) {
			ans.emplace_back(perm);
			return;
		}
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
				continue;
			}
			perm.emplace_back(nums[i]);
			vis[i] = 1;
			backtrack(nums, ans, idx + 1, perm);
			vis[i] = 0;
			perm.pop_back();
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> perm;
		vis.resize(nums.size());
		sort(nums.begin(), nums.end());
		backtrack(nums, ans, 0, perm);
		return ans;
	}
};
};

int main()
{
	Solution a;
	vector <int> nums{ 1,2,3,4,5 };
	a.permuteUnique(nums);
    return 0;
}

