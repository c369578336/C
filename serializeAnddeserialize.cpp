// serializeAnddeserialize.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

 //struct TreeNode {
 //    int val;
 //    TreeNode *left;
 //    TreeNode *right;
 //    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 //};
class Node
{
public:
	Node * next;
	TreeNode* val;
	Node();
	Node(TreeNode*);
};
Node::Node()
{
	next = NULL;
	val = NULL;
}
Node::Node(TreeNode* node)
{
	next = NULL;
	val = node;
}
class Codec {
public:
	// Encodes a tree to a single string.
	Node * seri(TreeNode* root)
	{
		Node* head=new Node;
		Node* tail = head;
		head->val = root;
		if (root)
		{
			tail->next = seri(root->left);
			while (tail->next)
			{
				tail = tail->next;
			}
			tail->next = seri(root->right);
			while (tail->next)
			{
				tail = tail->next;
			}
		}
		return head;
	}
	Node* serialize(TreeNode* root) {
		Node* head = seri(root);
		return head;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(Node* node) {
		TreeNode* root = node->val;
		if (node->val)
		{
			*node = *(node->next);
			root->left = deserialize(node);
			*node = *(node->next);
			root->right = deserialize(node);
		}
		return root;
	}
};


int main()
{
	TreeNode* root=new TreeNode(0);
	TreeNode* tree = root;
	for (int i = 1; i < 3; i++)
	{
		tree->left = new TreeNode(i);
		tree->right = new TreeNode(i + 10);
		tree = tree->left;
	}
	Codec a;
	root=a.deserialize(a.serialize(root));
    return 0;
}

