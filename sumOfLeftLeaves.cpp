// sumOfLeftLeaves.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int sumOfLeftLeaves(TreeNode* root) {
	if (!root) return 0;
	else
	{
		if (root->left)
		{
			if (root->left->left == NULL && root->left->right == NULL)
				return root->left->val + sumOfLeftLeaves(root->right);
			else
			{
				return sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
			}
		}
		return sumOfLeftLeaves(root->right);
	}
	return 0;
}

int main()
{
	TreeNode* root;
	sumOfLeftLeaves(root);
    return 0;
}

