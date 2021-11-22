// minKBitFlips: 定义控制台应用程序的入口点。

#include <stdio.h>
#include <tchar.h>
#include "vector"
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        int n = A.size();
        vector<int> diff(n + 1);
        int ans = 0, revCnt = 0;
        for (int i = 0; i < n; ++i) {
            revCnt += diff[i];
            if ((A[i] + revCnt) % 2 == 0) {
                if (i + K > n) {
                    return -1;
                }
                ++ans;
                ++revCnt;
                --diff[i + K];
            }
        }
        return ans;
    }
};

int main()
{
	Solution a;
    vector<int> A={
		{0,1,0}
	};
	int K=2;
	int ans=a.minKBitFlips(A,K);
    return 0;
}
