// removeDuplicateNodes.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	ListNode * removeDuplicateNodes(ListNode* head) {
		ListNode* ans = NULL;
		if (head == NULL) return NULL;
		else
		{
			ListNode* n = head;
			ans = new ListNode(n->val);;
			ListNode* ansNode = ans;
			int bools[20001] = { 0 };
			bools[n->val] = 1;
			n = n->next;
			while (n!=NULL)
			{
				if (!bools[n->val])
				{
					ansNode->next = new ListNode(0);
					ansNode = ansNode->next;
					ansNode->val = n->val;
					bools[n->val] = 1;
				}
				n = n->next;
			}
			ansNode = NULL;
		}
		return ans;
	}
};

int main()
{
	ListNode* head=new ListNode(0);
	ListNode* n=head;
	for (int i = 2; i < 20; i++)
	{
		n->next = new ListNode(i / 2);
		n = n->next;
	}
	Solution a;
	a.removeDuplicateNodes(head);
    return 0;
}

