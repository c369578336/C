// mergeTrees.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	if (!t1 && !t2)
	{
		return NULL;
	}
	TreeNode* ans;
	int t=0;
	if (t1)
		t += t1->val;
	if (t2)
		t += t2->val;
	ans = new TreeNode(t);
	ans->left = mergeTrees(t1->left, t2->left);
	ans->right = mergeTrees(t1->right, t2->right);
	return ans;
}

int main()
{
	TreeNode* root1 = new TreeNode(2);
	//root->left = new TreeNode(0);
	root1->right = new TreeNode(4);
	root1->right->left = new TreeNode(3);
	//->right->right = new TreeNode(5);
	root1->right->left->right = new TreeNode(3);
	root1->right->left->right->left = new TreeNode(3);
	root1->right->left->right->right = new TreeNode(3);
	TreeNode* root = new TreeNode(2);
	//root->left = new TreeNode(0);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(3);
	//->right->right = new TreeNode(5);
	root->right->left->right = new TreeNode(3);
	root->right->left->right->left = new TreeNode(3);
	root->right->left->right->right = new TreeNode(3);
	mergeTrees(NULL, NULL);
    return 0;
}

