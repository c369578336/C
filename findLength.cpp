// findLength.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		if (A. empty() || B. empty())
			return 0;
		int AL = A.size();
		int BL = B.size();
		int max = 0;
		for (int i = 0; i < AL-max; i++)
		{
			int s = 0;
			for (int j = 0; i + j < AL && j < BL; j++)
				if (A[i + j] == B[j])
				{
					s = 1;
					j++;
					while (i + j < AL && j < BL && A[i + j] == B[j])
					{
						s++;//A[I]=B[I]
						j++;
					}
					if (s > max) max = s;
				}
		}
		for (int i = 0; i < BL - max; i++)
		{
			int s = 0;
			for (int j = 0; i + j < BL && j < AL; j++)
				if (B[i + j] == A[j])
				{
					s = 1;
					j++;
					while (i + j < BL && j < AL && B[i + j] == A[j])
					{
						s++;//A[I]=B[I]
						j++;
					}
					if (s > max) max = s;
				}
		}
		return max;
	}
};

int main()
{
	vector <int> A = { 0, 0, 0, 0, 1 };
	vector <int> B = { 1, 0, 0, 0, 0 };
	Solution a;
	a.findLength(A, B);
    return 0;
}

