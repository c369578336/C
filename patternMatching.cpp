// patternMatching.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	bool patternMatching(string pattern, string value) {
		if (pattern.empty())
			if (value.empty())
				return true;
			else return false;
		string s1 = "";
		string s2 = "";
		int a=-1;
		int b=-1;
		int l1 = 0;
		int l2 = 0;
		for (int i = 0; i < pattern.length(); i++)
		{
			if (pattern[i] == 'a')
			{
				l1++;
				if (a==-1)
				a = i;
			}
			else
			{
				l2++;
				if (b==-1)
				b = i;
			}
		}
		if (l1 == 0&&value.length()% l2 == 0)
		{
				bool flag = 1;
				int n = value.length()/ l2;
				s2 = value.substr(0, n);
				int l = 0;
				for (int i = 0; i < pattern.length() && flag; i++)
				{
					if (s2 != value.substr(l, n))
						flag = 0;
					l = l + n;
				}
				if (flag)
					return true;
		}
		if (l2 == 0 && value.length() % l1 == 0)
		{
			bool flag = 1;
			int m = value.length() / l1;
			s1 = value.substr(0, m);
			int l = 0;
			for (int i = 0; i < pattern.length() && flag; i++)
			{
				if (s1 != value.substr(l, m))
					flag = 0;
				l = l + m;
			}
			if (flag)
				return true;
		}
		if (l1!=0&& l2!=0)
		for (int m = 0; m <= value.length()/l1|| m <= value.length() / l2; m++)
		{
			if ((value.length() >= l1 * m) && (value.length() - l1 * m) % l2 == 0)
			{
				bool flag = 1;
				int n = (value.length() - l1 * m) / l2;
				s1 = value.substr(a*n, m);
				s2= value.substr(b * m, n);
				if (s1 == s2)
					flag = 0;
				int l = 0;
				for (int i = 0; i < pattern.length()&&flag; i++)
				{
					if (pattern[i] == 'a')
					{
						if (s1 != value.substr(l, m))
							flag = 0;
						l = l + m;
					}
					else
					{
						if (pattern[i] == 'b')
						{
							if (s2 != value.substr(l, n))
								flag = 0;
							l = l + n;
						}
					}
				}
				if (flag)
					return true;
			}
		}
		return false;
	}
};

int main()
{

	Solution a;
		string s1 = "aaaabaaaaaaabaaaaaaaaaabaa";
	string s2 = "uuuuruuuuuuuuruuutuuuuuuuruuu";
	cout<<a.patternMatching(s1, s2);
    return 0;
}

