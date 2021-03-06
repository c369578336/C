// recoverFromPreorder.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class Node
{
public:
	Node * next;
	int val;
	int d;
	Node();
	Node(int,int);
};
Node::Node()
{
	next = NULL;
	val =0;
	d = 0;
}
Node::Node(int v,int D)
{
	next = NULL;
	val = v;
	int d = D;
}
class Solution {
public:
	TreeNode * deserialize(Node* node) {
		TreeNode* root = new TreeNode(node->val);
		if (node->next)
		{
			int d = node->d;
			if (d < node->next->d)
			{
				*node = *(node->next);
				root->left = deserialize(node);

			}
			if (node->next && d < node->next->d)
			{
				*node = *(node->next);
				root->right = deserialize(node);
			}
		}
		return root;
	}
	TreeNode * recoverFromPreorder(string S) {
		Node* root=new Node();
		Node* n = root;
		int t = 0;
		int d = 0;
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] == '-')
			{
				n->d = d;
				d = 0;
				while (S[i] == '-')
				{
					i++;
					d++; 
				}
				n->val = t;
				n->next = new Node();
				n = n->next;
				t = 0;
				i--;
			}
			else
			{
				t = t * 10 + S[i] - '0';
			}
		}
		n->val = t;
		n->d = d;
		TreeNode* ans = deserialize(root);
		return ans;
	}
};

int main()
{
	string str = "1-2--3---4-5--6---7";
	Solution a;
	a.recoverFromPreorder(str);
    return 0;
}

