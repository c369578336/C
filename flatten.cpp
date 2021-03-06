// flatten.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	TreeNode * solve(TreeNode* root)
	{
		if (root)
		{
			TreeNode* R=new TreeNode(root->val);
			TreeNode* Node;
			Node=R;
			Node->right = solve(root->left);
			while(Node->right)
				Node = Node->right;
			Node->right = solve(root->right);
			return R;
		}
		return NULL;
	}
	void flatten(TreeNode* root) {
		if (root)
		{
			TreeNode *R = solve(root);
			*root = *R;
		}
	}
};

int main()
{
	Solution a;
	TreeNode* root;
	root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(5);
	a.flatten(NULL);
    return 0;
}

