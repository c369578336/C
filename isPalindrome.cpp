// isPalindrome.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class Solution {
public:
	bool isPalindrome(string s) {
		int l = s.length();
		if (l)
		{
			int i = 0;
			int j = l - 1;
			while (i<j)
			{
				while (i<j &&(!(s[i] >= 'a' &&s[i] <= 'z') && !(s[i] >= 'A' &&s[i] <= 'Z')&& !(s[i] >= '0' &&s[i] <= '9')))
				{
					i++;
				} 
				while (i<j && (!(s[j] >= 'a' &&s[j] <= 'z') && !(s[j] >= 'A' &&s[j] <= 'Z') && !(s[j] >= '0' &&s[j] <= '9')))
				{
					j--;
				}
				if ((s[i] >= 'A' &&s[i] <= 'Z'))
					s[i] = s[i] - 'A' + 'a';
				if ((s[j] >= 'A' &&s[j] <= 'Z'))
					s[j] = s[j] - 'A' + 'a';
				if (s[i] != s[j])
					return false;
				i++;
				j--;
			}
		}
		return true;
	}
};

int main()
{
	Solution a;
	string s = "A man, a plan, a canal: Panama";
	cout << a.isPalindrome(s);
    return 0;
}

