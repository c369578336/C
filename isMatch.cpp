// isMatch.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.length();
		int n = p.length();
		if (n == 0)
			if (m == 0)
				return true;
			else
				return false;
		if (p[n - 1] == '?')
		{
			if (m != 0)
				return isMatch(s.substr(0, m - 1), p.substr(0, n-1));
			else return false;
		}
		else
		{
			if (m > 0)
			{
				if ((p[n - 1] == s[m - 1]))
					return isMatch(s.substr(0, m - 1), p.substr(0, n - 1));
				else if (p[n - 1] == '*')
				{	
					if (n == 1) return true;
					while (p[n - 2] == '*')
					{
						n--;
						if (n == 1) return true;
					}
					if (p[n-2]==s[m-1]|| p[n - 2] == '?')
						return isMatch(s.substr(0, m), p.substr(0, n - 1))|| isMatch(s.substr(0, m - 1), p.substr(0, n));
					else
					{
						return isMatch(s.substr(0, m - 1), p.substr(0, n));
					}
				}
					
				else return false;
			}
			else if (p[n - 1] == '*') 
				return isMatch("", p.substr(0, n - 1));
			else return false;
		}
	}
};

int main()
{
	Solution a;
	string s = "ab";
	string p = "?*";
	cout<<a.isMatch(s, p);
    return 0;
}
