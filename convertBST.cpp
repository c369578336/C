// convertBST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int sum=0;
TreeNode* convertBST(TreeNode* root) {
	if (!root)
		return NULL;
	else {
		if (root->right)
			convertBST(root->right);
		sum += root->val;
		root->val = sum;
		if (root->left)
			convertBST(root->left);
	}
	return root;
}

int main()
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(0);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(5);
	convertBST(root);
    return 0;
}

