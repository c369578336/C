// minCameraCover.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct status
{
	int flag=1;
	int sum=0;
};
bool isleaf(TreeNode* root)
{
	if (!root->left && !root->right)
		return true;
	else
	{
		return false;
	}
}
status CameraCover(TreeNode* root)
{
	if (isleaf(root))
		return { 0, 0 };
	else
	{
		status t1;
		if (root->left)
		{
			t1 = CameraCover(root->left);
		}
		status t2;
		if (root->right)
		{
			t2 = CameraCover(root->right);
		}
		if (t1.flag && t2.flag)
			return { 0,t1.sum + t2.sum };
		else return { 1,t1.sum + t2.sum + 1 };
	}
}
int minCameraCover(TreeNode* root) {
	if (!root)
		return 0;
	else if (isleaf(root))
		return 1;
	else
	{
		auto ans=CameraCover(root);
		return ans.sum;
	}
}

int main()
{
	TreeNode* root = new TreeNode(2);
	//root->left = new TreeNode(0);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(3);
	//->right->right = new TreeNode(5);
	root->right->left->right = new TreeNode(3);
	root->right->left->right->left = new TreeNode(3);
	root->right->left->right->right = new TreeNode(3);
	//root->right->left = new TreeNode(3);
	minCameraCover(root);
    return 0;
}

