// sortedArrayToBST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	vector<int> n;
	TreeNode * BST(int l,int r)
	{
		if (l > r) return NULL;
		if (l == r) return new TreeNode(n[l]);
		else
		{
			int mid = (l + r + 1) / 2;
			TreeNode* t = new TreeNode(n[mid]);
			t->left = BST(l, mid-1);
			t->right = BST(mid+1, r);
			return t;
		}
	}
	TreeNode * sortedArrayToBST(vector<int>& nums) {
		if (nums.empty()) return NULL;
		else
		{
			n = nums;
			return BST(0,nums.size()-1);
		}
	}
};

int main()
{
	vector <int> nums = { 0 };
	Solution a;
	a.sortedArrayToBST(nums);
    return 0;
}

