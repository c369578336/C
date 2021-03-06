// maxPathSum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int MAX = INT_MIN;
	int pathSum(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
		{
			if (MAX < root->val)
				MAX = root->val;
			return root->val;
		}
		else
		{
			int left=pathSum(root->left);
			int right = pathSum(root->right);
			if (left + right + root->val > MAX)
			{
				MAX = left + right + root->val;
			}
			if (left > right)
			{
				if (MAX < left + root->val)
					MAX = left + root->val;
				if (left + root->val > root->val)
				return left + root->val;
				else return root->val;
			}
			else {
				if (MAX < right + root->val)
					MAX = right + root->val;
				if (right + root->val > root->val)
				return right + root->val;
				else return root->val;
			}
		}
	}
	int maxPathSum(TreeNode* root) {
		MAX = root->val;
		pathSum(root);
		return MAX;
	}
};

int main()
{
	Solution a;
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(2);
	root->right = new TreeNode(-2);
	root->right->left = new TreeNode(-1);
	root->right->right = new TreeNode(-1);
	cout<<a.maxPathSum(root);
    return 0;
}

