// matrixReshape: 定义控制台应用程序的入口点。

#include <stdio.h>
#include <tchar.h>
#include "vector"
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int r0=nums.size();
		if (r0==0) return nums;
		int c0=nums[0].size();
		if (r0*c0==0 || r0*c0!=r*c) return nums;
		int m=0;
		int n=0;
		vector<vector<int>> ans(r, vector<int>(c));
		for (int i=0;i<r0;i++)
			for (int j=0;j<c0;j++)
			{
				ans[n][m]=nums[i][j];
				m++;
				if (m==c)
				{
					m=0;
					n++;
					if (n==r)
					return ans;
				}
			}
		return ans;
    }
};

int main()
{
	Solution a;
    vector<vector<int>> nums={
		{1,2,3,4}
		
	};
	int r=2;
	int c=2;
	nums=a.matrixReshape(nums,r,c);
    return 0;
}

