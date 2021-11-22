// isSameTree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q)
			return true;
		if (p && q)
		{
			if (p->val == q->val)
			{
				if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
					return true;
				else
				{
					return false;
				}
			}
			else return false;
		}
		else return false;
	}
};

int main()
{
    return 0;
}

