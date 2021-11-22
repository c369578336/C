// longestOnes: 定义控制台应用程序的入口点。

//#include <stdio.h>
//#include <tchar.h>
//#include "vector"
//#include "iostream"
//#include "string"
//#include "algorithm"
//using namespace std;
#include "stdafx.h"

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        vector<int> a={};
        int ans=0;
        int i=0;
        int j=0;
        int n=0;
        int k=K;
        bool flag=A[i];
        int len=A.size();
        while (i<len)
        {
            int s=0;
            while (i<len && A[i]==flag)
            {
                s++;
                i++;
            }
            if (flag) a.push_back(s);
            else a.push_back(-s);
            flag=!flag;
        }
        return ans;
    }
};

int main()
{
	Solution a;
    vector<int> A={
		{0,1,1,0,1,1,0,1,1,0}
	};
	int K=2;
	int ans=a.longestOnes(A,K);
    return 0;
}
