// numTrees.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int numTrees(int n) {
		int* ans = new int[n+1];
		ans[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			ans[i] = 0;
			for (int j = 0; j < i; j++)
				ans[i] += ans[j] * ans[i - j-1];
		}
		cout << ans[n];
		return ans[n];
	}
};

int main()
{
	Solution a;
	a.numTrees(3);
    return 0;
}

