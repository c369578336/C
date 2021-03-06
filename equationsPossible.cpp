// equationsPossible.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
	int max(char a, char b)
	{
		if (a > b)
			return a;
		else return b;
	}
	int min(char a, char b)
	{
		if (a < b)
			return a;
		else return b;
	}
	bool equationsPossible(vector<string>& equations) {
		vector <vector<int>> arr(26);
		for (int i = 0; i < 26; i++)
		{
			arr[i].resize(26);
			arr[i][i] = 1;
		}
		for (int i = 0; equations.size() > i; i++)
		{
			if (equations[i][1] == '=')
			{
				int m = equations[i][0] - 'a';
				int n = equations[i][3] - 'a';
				if (m!=n)
				for (int k = 0; k < 26; k++)
				{
					
					if (arr[m][k] == 1 )
						if (arr[n][k] == 2)
							return false;
						else
						{
							arr[n][k] = 1;
							arr[k][n] = 1;
						}
					else if (arr[m][k] == 2)
						if (arr[n][k] == 1)
							return false;
						else
						{
							arr[n][k] = 2;
							arr[k][n] = 2;
						}
					if (arr[n][k] == 1)
						if (arr[m][k] == 2) 
							return false;
						else
						{
							arr[m][k] = 1;
							arr[k][m] = 1;
						}
					else if (arr[m][k] == 2) 
						if (arr[n][k] == 1)
							return false;
						else
						{
							arr[n][k] = 2;
							arr[k][n] = 2;
						}
				}
			}
			else
			{
				int m = equations[i][0] - 'a';
				int n = equations[i][3] - 'a';
				if (m!=n)
				for (int k = 0; k < 26; k++)
				{
					
					if (arr[m][k] == 1)
						if (arr[n][k] == 1)
							return false;
						else
						{
							arr[n][k] = 2;
							arr[k][n] = 2;
						}
					if (arr[n][k] == 1)
						if (arr[m][k] == 1)
							return false;
						else
						{
							arr[m][k] = 2;
							arr[k][m] = 2;
						}
				}
				else
				{
					return false;
				}
			}
			//for (int i = 0; i < 26; i++)
			//{
			//	for (int j = 0; j < 26; j++)
			//		cout << arr[i][j] << ' ';
			//	cout << endl;
			//}
			//cout << endl;
		}
		
		return true;
	}
};


int main()
{
	Solution a;
	vector <string> equations = { "c==c", "f!=a", "f==b", "b==c" };
	cout<<a.equationsPossible(equations);
    return 0;
}

