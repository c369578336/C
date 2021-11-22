// pathSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "stdafx.h"
bool isleaf(TreeNode* root)
{
	if (root->left == NULL && root->right == NULL)
		return true;
	else
	{
		return false;
	}
	return false;
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector <vector <int>> ans;
	if (!root)
		return ans;
	if (isleaf(root))
	{
		if (sum == root->val)
		{
			vector <int> t{ root->val };
			ans.push_back(t);
			return ans;
		}
		else
		{
			return ans;
		}
	}
	sum -= root->val;
	if (root->left)
	{
		vector <vector <int>> t=pathSum(root->left,sum);
		for (int i = 0; i < t.size(); i++)
		{
			t[i].insert(t[i].begin(), root->val);
			ans.push_back(t[i]);
		}
	}
	if (root->right)
	{
		vector <vector <int>> t = pathSum(root->right, sum);
		for (int i = 0; i < t.size(); i++)
		{
			t[i].insert(t[i].begin(), root->val);
			ans.push_back(t[i]);
		}
	}
	return ans;
}
int main()
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(0);
	root->right = new TreeNode(1);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(5);
	root->right->left->right = new TreeNode(3);
	root->right->left->right->left = new TreeNode(3);
	root->right->left->right->right = new TreeNode(3);
	root->left->left = new TreeNode(5);
	root->left->left->right = new TreeNode(1);
	pathSum(root, 8);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
