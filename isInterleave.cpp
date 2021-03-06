// isInterleave.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		if (s1 + s2 == s3)
			return true;
		else
		{
			int flag1 = 0;
			int flag2 = 0;
			if (s1[flag1] == s3[flag1])
				flag1++;
			if (s2[flag2] == s3[flag2])
				flag2 ++;
			if ((flag1 && isInterleave(s1.substr(flag1),s2,s3.substr(flag1))) || (flag2 && isInterleave(s1, s2.substr(flag2), s3.substr(flag2))))
				return true;
			else
			{
				return false;
			}
		}
		return false;
	}
};

int main()
{
	string s1 = "cb";
	string s2 = "dbbca";
	string s3 = "dbcbcab";
	Solution a;
	cout<<a.isInterleave(s1, s2, s3);
    return 0;
}

