// longestValidParentheses.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int longestValidParentheses(string s) {
		int ans = 0;
		int stack = 0;
		int l = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
			{
				stack++;
			}
			else
				if (stack)
				{
					l+=2;
					stack--;
					if (stack==0 && l > ans)
						ans = l;
				}
				else l = 0;
		}
		if (ans == s.length()) return ans;
		stack = 0;
		l = 0;
		for (int i = s.length()-1; i >=0 ; i--)
		{
			if (s[i] == ')')
			{
				stack++;
			}
			else
				if (stack)
				{
					l += 2;
					stack--;
					if (stack==0 && l > ans)
						ans = l;
				}
				else l = 0;
		}
		
		return ans;
	}
};
	//int longestValidParentheses(string s) {
	//	int maxans = 0, n = s.length();
	//	vector<int> dp(n, 0);
	//	for (int i = 1; i < n; i++) {
	//		if (s[i] == ')') {
	//			if (s[i - 1] == '(') {
	//				dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
	//			}
	//			else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
	//				dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
	//			}
	//			maxans = max(maxans, dp[i]);
	//		}
	//	}
	//	return maxans;
	//}


int main()
{
	string s = "())()";
	Solution a;
	a.longestValidParentheses(s);
    return 0;
}

