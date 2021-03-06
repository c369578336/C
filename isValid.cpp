// isValid.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	bool isValid(string s) {
		vector <char> store;
		if (s == "")
			return true;
		else
			if ((s.length() % 2))
				return false;
			else
			{
				int i = 0;
				while (i < s.length())
				{
						switch (s[i])
						{
						case '(':store.push_back('('); break;
						case '[':store.push_back('['); break;
						case '{':store.push_back('{'); break;
						case ')':
							if ((store.size())&&store.back() == '(')
								store.pop_back();
							else return false;
							break;
						case ']':
							if ((store.size()) && store.back() == '[')
								store.pop_back();
							else return false;
							break;
						case '}':
							if ((store.size()) && store.back() == '{')
								store.pop_back();
							else return false;
							break;
						default:
							break;
						}
					i++;
				}
			}
		if (store.empty())
		return true;
		else return false;
	}
};

int main()
{
	Solution a;
	cout<<a.isValid("[");
    return 0;
}

