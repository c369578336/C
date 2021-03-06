// generateTrees.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	vector<vector<vector <TreeNode*>>> solve;
	void generate(int l, int r)
	{
		for (int i = l; i <= r; i++)
		{
			TreeNode* t = new TreeNode(i);
			if (l <i - 1 && !solve[l][i - 1].size()) generate(l, i - 1);
			if (i+1<r && !solve[i][r - 1].size()) generate(i+1, r);
			for (int j = 0; j < solve[l][i - 1].size(); j++)
			{
				t->left = solve[l][i - 1][j];
				for (int k = 0;i+1<r && k < solve[i+1][r].size(); k++)
				{
					t->right = solve[i+1][r][k];
					solve[l][r].push_back(t);
				}
			}
		}
	}
	vector<TreeNode*> generateTrees(int n) {
		solve.resize(n+1, vector <vector<TreeNode*>>(n+1));
		for (int i = 1; i <= n; i++)
		{
			solve[0][i].push_back(NULL);
			solve[i][0].push_back(NULL);
			solve[i][i].push_back(new TreeNode(i));
			for (int j = i+1; j <= n; j++)
				solve[j][i].push_back(NULL);
		}
		solve[0][0].push_back(NULL);
		generate(1, n);
		return solve[1][n];
	}
};

int main()
{
	Solution a;
	a.generateTrees(2);
    return 0;
}

