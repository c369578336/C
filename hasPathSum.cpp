// hasPathSum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root)
		{
			if (!root->left && !root->right)
			{
				if (sum - root->val == 0)
					return true;
				else
				{
					return false;
				}
			}
			if (root->left && hasPathSum(root->left, sum - root->val))
				return true;
			if (root->right && hasPathSum(root->right, sum - root->val))
				return true;
		}
		return false;
	}
};

int main()
{
	Solution a;
	TreeNode* root=new TreeNode(0);
	TreeNode* n=root;
	for (int i = 0; i < 5; i++)
	{
		n->left = new TreeNode(i);
		n->right = new TreeNode(i);
		n = (n->left);
	}
	n->val++;
	cout << a.hasPathSum(root,0);
    return 0;
}

