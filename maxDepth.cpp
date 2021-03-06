// maxDepth.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		else
		{
			int l = maxDepth(root->left)+1;
			int r = maxDepth(root->right) + 1;
			if (l > r)return l;
			else return r;
		}
	}
};

int main()
{
	Solution a;
	TreeNode *root=new TreeNode (0);
	root->left = new TreeNode(0);
	cout << a.maxDepth(root);
    return 0;
}

