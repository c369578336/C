// threeSum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector <int> n = nums;
		vector<vector <int>> ans;
		if (n.size() < 3) return ans;
		sort(n.begin(), n.end());
		int m = 0;
		int length = n.size();
		if (n[0]<=0 && n.back()>=0)
			while (m<length && n[m] <= 0)
			{
				int s = n[m];
				int i = m + 1;
				int j = n.size() - 1;
				while (i<j)
				{
					if (s + n[i] + n[j] == 0)
					{
						ans.push_back({ n[m],n[i],n[j] });
						while (i < j && n[i] == n[i + 1])
						{
							i++;
						}
						while (i < j && n[j] == n[j - 1])
						{
							j--;
						}
						i++;
						j--;
						
					}
					if (i<j && s + n[i] + n[j] < 0)
					{
						i++;
					}
					if (i<j && s + n[i] + n[j] > 0)
						j--;
				}
				m++;
				while (m<length && n[m] <= 0 && n[m] == n[m-1])
				{
					m++;
				}
				
			}
		return ans;
	}
};

int main()
{
	Solution a;
	vector <int> nums = {1,-1,-1,0};
	a.threeSum(nums);
    return 0;
}

