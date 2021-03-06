// maxScoreSightseeingPair.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		
		int m=1;
		int MAX=A[0];
		int ans = ans = A[m] - m + MAX;
		for (int i = 1; i <A.size()  ; i++)
		{
			if (A[i] - i+MAX > ans)
			{
				m = i;
				ans = A[i] - i+MAX;
			}
			if (A[i] + i > MAX)
			{
				MAX = A[i] + i;
			}
		}
		return ans;
	}
};

int main()
{
	Solution A;
	vector <int> arr = { 1,3,5 };
	cout << A.maxScoreSightseeingPair(arr);
    return 0;
}

