// climbStairs.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		int p = 1;
		int q = 2;
		int ans;
		for (int i = 0; i < n-2; i++)
		{
			ans = p + q;
			p = q;
			q = ans;
		}
		return ans;
	}
};

int main()
{
	Solution a;
	a.climbStairs(6);
    return 0;
}

