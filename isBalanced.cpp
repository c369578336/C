// isBalanced.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int high(TreeNode* root)
	{
		int left, right;
		if (!root->left) left = 0;
		else left = high(root->left);
		if (!root->right) right = 0;
		else right = high(root->right);
		if (abs(left - right) > 1) return -1;
		if (left == -1 || right == -1)
			return -1;
		else return max(left, right) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		if (high(root) == -1)return false;
		else return true;
	}
};

int main()
{
    return 0;
}

