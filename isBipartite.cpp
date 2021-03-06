// isBipartite.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	vector <int> arr;
	bool Bipartite(vector<vector<int>>& graph,int index)
	{
		bool flag = !arr[index];
		for (int i = 0; i < graph[index].size(); i++)
		{
			if (arr[graph[index][i]] == -1)
			{
				arr[graph[index][i]] = flag;
				if (!Bipartite(graph, graph[index][i]))
					return false;
			}
			else if (arr[graph[index][i]] != flag)
				return false;
		}
		return true;
	}
	bool isBipartite(vector<vector<int>>& graph) {
		arr.resize(graph.size(), -1);
		int i = 0;
		while (i<graph.size())
		{
			arr[i] = 1;
			if (Bipartite(graph, i))
			{
				while (i<graph.size() && arr[i] != -1)
				{
					i++;
				}
			}
			else
			{
				return false;
			}
		}
		return true;
	}
		int searchInsert(vector<int>& nums, int target) {
			int l = 0;
			int r = nums.size() - 1;
			while (l<r)
			{
				if (nums[(l + r) / 2]>target)
					r = (l + r) / 2-1;
				else if (nums[(l + r) / 2] < target)
				{
					l = (l + r) / 2+1;
				}
				else return (l + r) / 2;
			}
			return r;
		}
};

int main()
{
	Solution a;
	vector <int> arr = { 1,3,5,6 };
	cout<<a.searchInsert(arr,7);
    return 0;
}

