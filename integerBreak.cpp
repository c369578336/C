// integerBreak.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	vector <int> ans;
	void Break(int n) {
		for (int i = 1; i <= (n+1)/2; i++)
		{
			int t;
			if (!ans[n - i]) Break(n - i);
			t = max(i*(ans[n - i]), i*(n - i));
			ans[n] = max(t, ans[n]);
		}
	}
	int integerBreak(int n) {
		ans.resize(59);
		ans[1] = 1;
		ans[2] = 1;
		Break(n);
		return ans[n];
	}
};

int main()
{
	Solution a;
	a.integerBreak(10);
    return 0;
}

