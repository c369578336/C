// translateNum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
#include "iostream"

class Solution {
public:
	int translateNum(int num) {
		int t = 1;
		int p = 1;
		int q = 1;
		int k = 0;
		while (num)
		{
			if (num % 100 < 26 && num % 100 > 9)
				k = 1;
			else k = 0;
			t = p + q * k;
			q = p;
			p = t;
			num /= 10;
		}
		return t;
	}
};
int main()
{
	Solution a;
	int m;
	std::cin >> m;
	std::cout<<a.translateNum(m);
    return 0;
}

